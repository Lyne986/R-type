/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** ListRoom
*/

#ifndef __RT_SERVER_NETWORK_MESSAGE_PARSER_LIST_ROOM_HPP__
    #define __RT_SERVER_NETWORK_MESSAGE_PARSER_LIST_ROOM_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "GameLogic/PartyManager.hpp"
    #include <GameEngineNetwork.hpp>

namespace RT::Server::Network::Message::Parser {
    class ListRoom : public AParser {
        private:
            std::shared_ptr<GameLogic::PartyManager> partyManager = GameLogic::PartyManager::getInstance();

        public:
            ListRoom(MyServer &server);
            void parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg);
    };
}

#endif