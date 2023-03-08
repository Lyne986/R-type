/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** ServerInterface
*/


#ifndef SERVERINTERFACE_HPP_
	#define SERVERINTERFACE_HPP_

	#pragma once // For windows ? maybe
	#include "Network/Utils.hpp"
	#include "Network/ThreadQueue.hpp"
	#include "Network/Connection.hpp"
	#include "Network/OwnedMessage.hpp"
    #include "Utils/Debug/Log.hpp"

template<typename T>
class ServerInterface {

    public:

        ServerInterface(uint16_t port): _acceptor(_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), port)){}
        ~ServerInterface()
        {
            Stop();
        }

        bool Start() // Start server -> Seek Client Connection.
        {
            try {

                WaitClients();
                _contexThread = std::thread([this]()
                    {
                        _context.run();
                    });

            } catch (std::exception &e) {

                std::cerr << "[SERVER] Something went wrong : " << e.what() << "\n";
                return false;

            }

            RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::ServerNetwork, "[SERVER] Started!");
            return true;
        }


        void Stop()
        {
            _context.stop();

            if (_contexThread.joinable())
                _contexThread.join();
        }


        void WaitClients()
        {
            _acceptor.async_accept(
                [this](std::error_code error, asio::ip::tcp::socket socket)
                {

                    if (error)
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::ServerNetwork, "[SERVER] Connection Error : " + error.message());
                    else {
                        RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::ServerNetwork, "[SERVER] New Connection Detected");
                        // std::cout << "[SERVER] New Connection Detected : " << socket.remote_endpoint();

                        std::shared_ptr<Connection<T>> newConnection = std::make_shared<Connection<T>>(Connection<T>::owner::server,
                        _context, std::move(socket), _inputMQueue);

                        if (OnConnection(newConnection)) {
                            _connections.push_back(std::move(newConnection));
                            _connections.back()->ConnectToClient(_idCounter++);

                            RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::ServerNetwork, "[" + std::to_string(_connections.back()->GetID()) + "] Connection Approved");
                        } else
                            RT::GE::Utils::Debug::Log::LogMessage(RT::GE::Utils::Debug::Log::ServerNetwork, "[None] Connection Declined");
                    }

                    WaitClients();
                });
        }

        void SendMessage(std::shared_ptr<Connection<T>> client, const message_s<T>& msg)
        {
            if (client && client->isConnected())
                client->Send(msg);
            else {
                OnDisconnect(client);
                client.reset();
                _connections.erase(std::remove(_connections.begin(), _connections.end(), client), _connections.end());
            }
        }


        void SendAllMessage(const message_s<T>& msg)
        {
            bool invalid = false;

            for (std::shared_ptr<Connection<T>>& client : _connections) // check si le for marche
            {
                if (client && client->isConnected()) {
                    client->Send(msg);
                } else {
                    OnDisconnect(client);
                    client.reset();

                    invalid = true;
                }
            }

            if (invalid)
                _connections.erase(std::remove(_connections.begin(), _connections.end(), nullptr), _connections.end());
        }


        void Update(size_t nbrMax, bool waiting)
        {
            if (waiting)
                _inputMQueue.wait();

            for (size_t i = 0; i < nbrMax && !_inputMQueue.isEmpty(); i++) {
                auto msg = _inputMQueue.pop_front();

                OnMessage(msg.remote, msg.msg);
            }
        }

    protected:
			virtual bool OnConnection(std::shared_ptr<Connection<T>>)
			{
				return false;
			}
			virtual void OnDisconnect(std::shared_ptr<Connection<T>> client) = 0;
			virtual void OnMessage(std::shared_ptr<Connection<T>> client, message_s<T>& msg) = 0;

        SafeThreadQueue<owned_message_s<T>> _inputMQueue;
        std::deque<std::shared_ptr<Connection<T>>> _connections;
        asio::io_context _context;
        std::thread _contexThread;
        asio::ip::tcp::acceptor _acceptor;
        uint32_t _idCounter = 1000;
};

#endif /* !SERVERINTERFACE_HPP_ */
