#ifndef __RT_SERVER_NETWORK_MESSAGE_PARSER_PARSER_HPP__
    #define __RT_SERVER_NETWORK_MESSAGE_PARSER_PARSER_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/MyServer.hpp"
    #include "Network/Message/Parser/JoinMessage.hpp"
    #include "Network/Message/Parser/PlayerPosition.hpp"
    #include "Network/Message/Parser/ShootPos.hpp"
    #include "Network/Message/Parser/Shoot.hpp"
    #include "Network/Message/Parser/PlayerDisconnect.hpp"
    #include "Network/Message/Parser/CreateRoom.hpp"
    #include "Network/Message/Parser/JoinRoom.hpp"
    #include "Network/Message/Parser/ListRoom.hpp"
    #include <GameEngineNetwork.hpp>

namespace RT::Server::Network::Message::Parser {
    class Parser {
        private:
            MyServer &server;
            JoinMessage joinMessage;
            PlayerPosition playerPosition;
            ShootPos shootPos;
            PlayerDisconnect playerDisconnect;
            CreateRoom createRoom;
            JoinRoom joinRoom;
            ListRoom listRoom;
            Shoot shoot;

        public:
            Parser(MyServer &server);
            void parseMessage(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg);
    };
}

#endif