/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** AClient
*/

#ifndef ACLIENT_HPP_
    #define ACLIENT_HPP_

    #include "Network/Utils.hpp"
    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Client {
    template <typename T>
    class AClient
    {
        public:
            virtual ~AClient() {
                disconnect();
            }
            AClient()
            {

            }

            bool connectUdp(std::string ip, int port) {
                return this->_connection->connectUdp(ip, port);
            }

            bool connect(const std::string &host, const uint16_t port)
            {
                try {
                    asio::ip::tcp::resolver tcp_resolver(_context);
                    asio::ip::tcp::resolver::results_type tcp_endpoints = tcp_resolver.resolve(host, std::to_string(port));

                    _connection = std::make_unique<Connection<T>>(Connection<T>::owner::client, _context, asio::ip::tcp::socket(_context), asio::ip::udp::socket(_context), _inputQueue, _inputQueueUdp);
                    _connection->ConnectToServer(tcp_endpoints);
                    std::cerr << "connected to server: " << "\n";
                    _contexThread = std::thread([this]() { _context.run(); });
                } catch (std::exception &e) {
                    std::cerr << "Client Exception: " << e.what() << "\n";
                    return false;
                }
                return true;
            }

            void disconnect()
            {
                if(isConnected())
                    _connection->Disconnect();

                _context.stop();

                if (_contexThread.joinable())
                    _contexThread.join();

                _connection.release();
            }

            bool isConnected()
            {
                if (_connection)
                    return _connection->isConnected();
                else
                    return false;
            }

            bool isConnectedUdp()
            {
                if (_connection)
                    return _connection->isConnectedUdp();
                else
                    return false;
            }

            void send(const message_s<T> &msg)
            {
                if (isConnected())
                    _connection->Send(msg);
            }

            void sendUDP(const message_s<T> &msg)
            {
                if (isConnectedUdp())
                    _connection->SendUDP(msg);
            }

            SafeThreadQueue<owned_message_s<T>> &incoming()
            {
                return _inputQueue;
            }

            SafeThreadQueue<owned_message_s<T>> &incomingUdp()
            {
                return _inputQueueUdp;
            }

        protected:
            asio::io_context _context;
            std::thread _contexThread;
            std::unique_ptr<Connection<T>> _connection;

        private:
            SafeThreadQueue<owned_message_s<T>> _inputQueue;
            SafeThreadQueue<owned_message_s<T>> _inputQueueUdp;
    };
}

#endif /* !AClient_HPP_ */