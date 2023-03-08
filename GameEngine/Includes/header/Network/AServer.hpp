#ifndef __RT_GE_NETWORK_ASERVER_HPP__
    #define __RT_GE_NETWORK_ASERVER_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Utils.hpp"
    #include "Network/ThreadQueue.hpp"
    #include "Network/Connection.hpp"
    #include "Network/OwnedMessage.hpp"
    #include "Network/Message.hpp"
    #include "Utils/Debug/Log.hpp"
    #include <GameEngineNetwork.hpp>

namespace RT::GE::Network::Server {
    template <typename T>
    class AServer {

        public:

            AServer(uint16_t port)
            : _acceptor(_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port))
            {

            }

            ~AServer()
            {
                stop();
            }

            bool start() // Start server -> Seek Client Connection.
            {
                try {
                    waitClients();
                    _contexThread = std::thread([this]()
                        {
                            _context.run();
                        });

                } catch (std::exception &e) {
                    std::cerr << "[SERVER] Something went wrong : " << e.what() << "\n";
                    return false;
                }
                Utils::Debug::Log::LogMessage(Utils::Debug::Log::ServerNetwork, "[SERVER] started!");
                return true;
            }

            void stop()
            {
                _context.stop();
                if (_contexThread.joinable())
                    _contexThread.join();
            }

            void waitClients()
            {
                _acceptor.async_accept(
                    [this](std::error_code error, asio::ip::tcp::socket socket)
                    {
                        int counter = 0;
                        if (error) {
                            Utils::Debug::Log::LogMessage(Utils::Debug::Log::ServerNetwork, "[SERVER] Connection Error : " + error.message());
                        } else {
                            Utils::Debug::Log::LogMessage(Utils::Debug::Log::ServerNetwork, "[SERVER] New Connection Detected");
                            // std::cout << "[SERVER] New Connection Detected : " << socket.remote_endpoint();
                        
                            std::shared_ptr<Connection<T>> newConnection = std::make_shared<Connection<T>>(Connection<T>::owner::server,
                            _context, std::move(socket), asio::ip::udp::socket(_context, asio::ip::udp::endpoint(asio::ip::udp::v4(), ++this->udpPort)), _inputMQueue, _inputMQueueUdp);

                            if (onConnection(newConnection)) {
                                std::shared_ptr<Connection<T>> nc = std::move(newConnection);
                                GE::Network::Message::UDPInit udpInit(this->udpPort);
                                // std::cout << "SENDING PORT : " << this->udpPort << "TO CLIENT NB : " << counter << std::endl;
                                counter++;
                                message_s<CustomMsgTypes> msg("UDPInit");
                                msg.header.id = CustomMsgTypes::ServerMessage;
                                msg << udpInit;
                                nc->Send(msg);
                                // this->client->send(msg);
                                _connections.push_back(nc);
                                _connections.back()->ConnectToClient(_idCounter++);
                                Utils::Debug::Log::LogMessage(Utils::Debug::Log::ServerNetwork, "[" + std::to_string(_connections.back()->GetID()) + "] TCP Connection Approved");
                            } else
                                Utils::Debug::Log::LogMessage(Utils::Debug::Log::ServerNetwork, "[TCP] Connection Declined");
                            

                        }
                        waitClients();
                    });
            }

            void sendMessage(std::shared_ptr<Connection<T>> client, const message_s<T>& msg)
            {
                if (client && client->isConnected())
                    client->Send(msg);
                else {
                    onDisconnect(client);
                    client.reset();
                    _connections.erase(std::remove(_connections.begin(), _connections.end(), client), _connections.end());
                }
            }

            void sendAllMessage(const message_s<T>& msg)
            {
                bool invalid = false;
                for (std::shared_ptr<Connection<T>>& client : _connections) {
                    if (client && client->isConnected()) {
                        client->Send(msg);
                    } else {
                        onDisconnect(client);
                        client.reset();
                        invalid = true;
                    }
                }
                if (invalid)
                    _connections.erase(std::remove(_connections.begin(), _connections.end(), nullptr), _connections.end());
            }

            void update(size_t nbrMax, bool waiting)
            {
                if (waiting)
                    _inputMQueue.wait();
                for (size_t i = 0; i < nbrMax && !_inputMQueue.isEmpty(); i++) {
                    auto msg = _inputMQueue.pop_front();
                    onMessage(msg.remote, msg.msg);
                }
            }

            void updateUdp(size_t nbrMax, bool waiting)
            {
                // std::cout << "updateUdp empty " << _inputMQueueUdp.isEmpty() << std::endl;
                if (waiting)
                    _inputMQueueUdp.wait();
                // std::cout << "updateUdp" << std::endl;
                for (size_t i = 0; i < nbrMax && !_inputMQueueUdp.isEmpty(); i++) {
                    auto msg = _inputMQueueUdp.pop_back();
                    // std::cout << "UDP Message Received\n";
                    onMessageUdp(msg.remote, msg.msg);
                }
            }


        protected:
                virtual bool onConnection(std::shared_ptr<Connection<T>>)
                {
                    return false;
                }
                virtual void onDisconnect(std::shared_ptr<Connection<T>> client) = 0;
                virtual void onMessage(std::shared_ptr<Connection<T>> client, message_s<T>& msg) = 0;
                virtual void onMessageUdp(std::shared_ptr<Connection<T>> client, message_s<T>& msg) = 0;

                int udpPort = 6000;
                SafeThreadQueue<owned_message_s<T>> _inputMQueue;
                SafeThreadQueue<owned_message_s<T>> _inputMQueueUdp;
                std::deque<std::shared_ptr<Connection<T>>> _connections;
                asio::io_context _context;
                std::thread _contexThread;
                asio::ip::tcp::acceptor _acceptor;
                uint32_t _idCounter = 1000;
    };

}

#endif
