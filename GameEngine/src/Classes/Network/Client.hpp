/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Client
*/

#ifndef CLIENT_HPP_
    #define CLIENT_HPP_

    #include "Network/Utils.hpp"
    #include "Network/ThreadQueue.hpp"
    #include "Network/OwnedMessage.hpp"
    #include "Network/AClient.hpp"
    #include "Network/Connection.hpp"
    #include "Network/Message/JoinMessage.hpp"
    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Client {
    class Client : public AClient<CustomMsgTypes>
    {
        public:
            Client();
            ~Client();
            void pingServer();
            void listRoom();
            void messageAll();
            void createRoom();
    };
}

#endif /* !CLIENT_HPP_ */
