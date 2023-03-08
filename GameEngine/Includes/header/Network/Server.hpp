/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Server
*/

#ifndef __RT_GE_NETWORK_SERVER_HPP__
    #define __RT_GE_NETWORK_SERVER_HPP__

    #include "Network/AServer.hpp"
    #include "Network/Message.hpp"
    #include "Network/Message/JoinMessage.hpp"
    #include "Network/Connection.hpp"
    #include "NetworkNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include <memory>

namespace RT::GE::Network::Server {
    class Server : public AServer<CustomMsgTypes>
    {
        public:
            Server(uint16_t nPort)
            : AServer<CustomMsgTypes>(nPort)
            {
                Utils::Debug::Log::LogMessage(Utils::Debug::Log::ServerNetwork, "Server has been created");
            }
            ~Server() {};

        protected:
            bool onConnection(std::shared_ptr<Connection<CustomMsgTypes>> client)
            {
                message_s<CustomMsgTypes> msg;
                msg.header.id = CustomMsgTypes::ServerAccept;
                client->Send(msg);

                return true;
            }

            virtual void onMessage(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) = 0;
            virtual void onMessageUdp(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) = 0;

            virtual void onDisconnect(std::shared_ptr<Connection<CustomMsgTypes>> client) = 0;
    };
}

#endif /* !__RT_GE_NETWORK_SERVER_HPP__ */
