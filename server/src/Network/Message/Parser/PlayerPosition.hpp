#ifndef __RT_SERVER_NETWORK_MESSAGE_PARSER_PLAYERPOSITION_HPP__
    #define __RT_SERVER_NETWORK_MESSAGE_PARSER_PLAYERPOSITION_HPP__
 
    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "Network/MyServer.hpp"
    #include "GameLogic/PartyManager.hpp"
    #include <memory>
    #include <GameEngineNetwork.hpp>
    #include <GameEngineUtils.hpp>

namespace RT::Server::Network::Message::Parser {
    class PlayerPosition : public AParser {
        private:
            std::shared_ptr<GameLogic::PartyManager> partyManager = GameLogic::PartyManager::getInstance();

        public:
            PlayerPosition(MyServer &server);
            void parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg);
    };
}

#endif