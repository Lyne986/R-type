    /*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Connection
*/

#ifndef CONNECTION_HPP_
    #define CONNECTION_HPP_

    #pragma once
    #include "Network/Utils.hpp"
    #include "Network/ThreadQueue.hpp"
    #include "Network/OwnedMessage.hpp"
    #include "Network/Message.hpp"
    #include "Network/Message/UDPInit.hpp"
    #include "Network/Message/PlayerPosition.hpp"
    #include "Utils/Debug/Log.hpp"

template<typename T>
struct owned_message_s;

template<typename T>
struct message_s;

template<typename T>
struct header_s;

template<typename T>
class Connection : public std::enable_shared_from_this<Connection<T>>
{
    public:
        enum class owner {
            server,
            client
        };

        Connection(owner parent, asio::io_context &asioContext, asio::ip::tcp::socket tsocket, asio::ip::udp::socket usocket, SafeThreadQueue<owned_message_s<T>> &qIn, SafeThreadQueue<owned_message_s<T>> &qInUdp)
            : _context(asioContext), _tcp_socket(std::move(tsocket)), _inputQueue(qIn), _udp_socket(std::move(usocket)), _inputQueueUdp(qInUdp)
        {
            _ownerType = parent;
        }

        uint32_t GetID() const
        {
            return _id;
        }

        void ConnectToClient(uint32_t uid)
        {
            if (_ownerType == owner::server) {
                if (_tcp_socket.is_open()) {
                    _id = uid;
                    ReadHeader();
                    UDPRead();
                }
            }
        }

        void ConnectToServer(const asio::ip::tcp::resolver::results_type& endpoints)
        {
            if (_ownerType == owner::client)
            {
                // _udp_socket.open(asio::ip::udp::v4());
                asio::async_connect(_tcp_socket, endpoints,
                    [this](std::error_code ec, asio::ip::tcp::endpoint)
                    {
                        if (!ec) {
                            ReadHeader();
                        }
                    });
                
            }
        }

        void Disconnect()
        {
            if (isConnected())
                asio::post(_context, [this]() { _tcp_socket.close(); });
        }

        bool isConnected() const
        {
            return _tcp_socket.is_open();
        }

        bool isConnectedUdp() const
        {
            return _udp_socket.is_open();
        }

        void SendUDP(const message_s<T>& msg)
        {
            int status = 0;
            // std::cout << "Send UDP " << " -- Connection : " << this->_id << std::endl;
            std::string msgType(msg.header.type);
            // std::cout << "MUST SEND TYPE -> " << msgType << std::endl;
            asio::post(_context, [this, msg]()
                {
                    // std::cout << "udp queue has : " << _udpOutgoingMessages.count() << " -- Connection : " << this->_id << std::endl;
                    bool bWritingMessage = _udpOutgoingMessages.isEmpty();
                    _udpOutgoingMessages.push_back(msg);
                    if (bWritingMessage) {
                        // std::cout << "UDP WRITE " << _id << std::endl;
                        // std::cout << "UDP Write" << std::endl;
                        WriteUDP();
                    }
                });
        }

        void WriteBodyUDP()
        {
            // print body
            if (owner::server == _ownerType) {
                // std::cout << "sending to " << this->_udp_remoteEndpoint.address().to_string() << ":" << this->_udp_remoteEndpoint.port() << std::endl;
            }
            this->_udp_socket.async_send_to(asio::buffer(_udpOutgoingMessages.getFront().body.data(), _udpOutgoingMessages.getFront().body.size()), this->_udp_remoteEndpoint,
                [this](std::error_code ec, std::size_t)
                {
                    if (!ec) {
                        _udpOutgoingMessages.pop_front();
                        if (!_udpOutgoingMessages.isEmpty()) {
                            // std::cout << "UDP Write back" << std::endl;
                            WriteUDP();
                        }
                    } else {
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::Network, "[" + std::to_string(_id) + "] Write Body Fail.");
                        // this->_udp_socket.close();
                    }
                });
        }

        void WriteUDP()
        {
            // std::cout << "Write UDP" << std::endl;
            this->_udp_socket.async_send_to(asio::buffer(&_udpOutgoingMessages.getFront().header, sizeof(header_s<T>)), this->_udp_remoteEndpoint,
                [this](std::error_code ec, std::size_t)
                {
                    if (!ec) {
                        if (_udpOutgoingMessages.getFront().body.size() > 0) {
                            // std::cout << "UDP Write Body " << _id << std::endl;
                            WriteBodyUDP();
                        } else {
                            // std::cout << "UDP Write body is zero " << _id << std::endl;
                            _udpOutgoingMessages.pop_front();

                            if (!_udpOutgoingMessages.isEmpty())
                                WriteUDP();
                        }
                    } else {
                        // std::cout << "UDP Write Fail " << _id << std::endl;
                        // std::cout << "ec message: " << ec.message() << std::endl;
                        // std::cout << "ec value: " << ec.value() << std::endl;
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::Network, "[" + std::to_string(_id) + "] Write Header Fail.");
                        // this->_udp_socket.close();
                        _udpOutgoingMessages.pop_front();
                        WriteUDP();
                    }
                });
        }

        void Send(const message_s<T>& msg)
        {
            asio::post(_context,
                [this, msg]()
                {
                    bool bWritingMessage = _queueOutput.isEmpty();

                    _queueOutput.push_back(msg);
                    if (bWritingMessage)
                        WriteHeader();
                });
        }

        bool connectUdp(std::string ip, int port)
        {
            try {
                this->_udp_socket.open(asio::ip::udp::v4());
                this->_udp_remoteEndpoint = asio::ip::udp::endpoint(asio::ip::make_address(ip), port);
                this->_udp_socket.connect(this->_udp_remoteEndpoint);
                // std::cout << "UDP connect to server" << std::endl;
                UDPRead();
                return true;
            } catch (std::exception& e) {
                std::cerr << e.what() << std::endl;
                return false;
            }
        }

    private:
        void WriteHeader()
        {
            asio::async_write(_tcp_socket, asio::buffer(&_queueOutput.getFront().header, sizeof(header_s<T>)),
                [this](std::error_code ec, std::size_t)
                {
                    if (!ec) {
                        if (_queueOutput.getFront().body.size() > 0)
                            WriteBody();
                        else {
                            _queueOutput.pop_front();

                            if (!_queueOutput.isEmpty())
                                WriteHeader();
                        }
                    } else {
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::Network, "[" + std::to_string(_id) + "] Write Header Fail.");
                        _tcp_socket.close();
                    }
                });
        }

        void WriteBody()
        {
            asio::async_write(_tcp_socket, asio::buffer(_queueOutput.getFront().body.data(), _queueOutput.getFront().body.size()),
                [this](std::error_code ec, std::size_t)
                {
                    if (!ec) {
                        _queueOutput.pop_front();

                        if (!_queueOutput.isEmpty())
                            WriteHeader();
                    } else {
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::Network, "[" + std::to_string(_id) + "] Write Body Fail.");
                        _tcp_socket.close();
                    }
                });
        }

        void ReadHeader()
        {
            asio::async_read(_tcp_socket, asio::buffer(&_queueInput.header, sizeof(header_s<T>)),
                [this](std::error_code ec, std::size_t)
                {
                    if (!ec) {
                        if (_queueInput.header.size > 0) {
                            _queueInput.body.resize(_queueInput.header.size);
                            ReadBody();
                        } else
                            AddQueue();
                    } else {
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::Network, "[" + std::to_string(_id) + "] Read Header Fail.");
                        _tcp_socket.close();
                    }
                });
        }

        void ReadBody()
        {
            asio::async_read(_tcp_socket, asio::buffer(_queueInput.body.data(), _queueInput.body.size()),
                [this](std::error_code ec, std::size_t)
                {
                    if (!ec)
                        AddQueue();
                    else {
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::Network, "[" + std::to_string(_id) + "] Read Body Fail.");
                        _tcp_socket.close();
                    }
                });
        }

        void AddQueue()
        {
            if(_ownerType == owner::server)
                _inputQueue.push_back({ this->shared_from_this(), _queueInput });
            else
                _inputQueue.push_back({ nullptr, _queueInput });

            ReadHeader();
        }

        void UDPReadBody()
        {
            if (_ownerType == owner::client) {
                // std::cout << "UDPReadBody" << std::endl;
            }
            _udp_socket.async_receive_from(asio::buffer(_queueInputUdp.body.data(), _queueInputUdp.body.size()), _udp_remoteEndpoint,
                [this](std::error_code ec, std::size_t)
                {
                    if (!ec) {
                        this->UDPAddStack();
                    } else {
                        std::cerr << "[" << _id << "] Read UDP Body Fail: " << ec.message() << "\n";
                        // _udp_socket.close();
                        UDPRead();
                    }
                });
        }

        void UDPRead()
        {
            if (_ownerType == owner::client) {
                // std::cout << "UDPRead" << std::endl;
            }
            _udp_socket.async_receive_from(asio::buffer(&_queueInputUdp.header, sizeof(header_s<T>)), _udp_remoteEndpoint,
                [this](std::error_code ec, std::size_t)
                {
                    if (_ownerType == owner::client) {
                        // std::cout << "UDP READ AS CLIENT N[" << _id << "]" << std::endl;
                    }
                    if (!ec) {
                        if (_queueInputUdp.header.size > 0) {
                            _queueInputUdp.body.resize(_queueInputUdp.header.size);
                            this->UDPReadBody();
                        } else {
                            // std::cout << "UDP Read Header Fail size == 0" << std::endl;
                            RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::Network, "[" + std::to_string(_id) + "] UDP Read Header Fail.");
                            // _udp_socket.close();
                            // UDPAddStack();
                            UDPRead();
                        }
                    } else
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::Network, "[" + std::to_string(_id) + " UDP] Read Fail.");
                });
        }

        void UDPAddStack()
        {
            // std::cout << "ADDING TO STACK UDP" << std::endl;
            // std::cout << "COUNT BEFORE ADD " << this->_inputQueueUdp.count() << std::endl;
            if (_ownerType == owner::client) {
                // std::cout << "ADDING STACK AS CLIENT N[" << _id << "]" << std::endl;
            }
            try {
                if(_ownerType == owner::server)
                    _inputQueueUdp.push_back({ this->shared_from_this(), _queueInputUdp });
                else
                    _inputQueueUdp.push_back({ nullptr, _queueInputUdp });
            } catch (std::exception& e) {
                // std::cout << "SERVER UDP ADD STACK EXCEPTION: " << e.what() << std::endl;
            }

            // // std::cout << "ADD UDP STACK END FUNC" << std::endl;
            // // std::cout << "COUNT AFTER ADD " << this->_inputQueueUdp.count() << std::endl;
            UDPRead();
        }

    public:
// ============== TCP VARS ============== //
        asio::ip::tcp::socket _tcp_socket;
        SafeThreadQueue<message_s<T>> _queueOutput;
        SafeThreadQueue<owned_message_s<T>> &_inputQueue;
        message_s<T> _queueInput;

// ============== UDP VARS ============== //
        asio::ip::udp::socket _udp_socket;
        SafeThreadQueue<message_s<T>> _udpOutgoingMessages;
        SafeThreadQueue<owned_message_s<T>> &_inputQueueUdp;
        message_s<T> _queueInputUdp;
        asio::ip::udp::endpoint _udp_remoteEndpoint;

// ============== VARS ============== //
        owner _ownerType = owner::server;
        uint32_t _id = 0;
        asio::io_context &_context;
};


#endif /* !CONNECTION_HPP_ */
