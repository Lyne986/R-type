#ifndef __RT_SERVER_NETWORK_MESSAGE_PARSER_PLAYERSHOOT_HPP__
    #define __RT_SERVER_NETWORK_MESSAGE_PARSER_PLAYERSHOOT_HPP__

    #include <GameEngineNetwork.hpp>
    #include <GameEngineUtils.hpp>
    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "GameLogic/PartyManager.hpp"

namespace RT::Server::Network::Message::Parser {
    class ShootPos : public AParser {
        private:
            std::shared_ptr<GameLogic::PartyManager> partyManager = GameLogic::PartyManager::getInstance();

        public:
            ShootPos(MyServer &server);
            void parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg);
    };
}

#endif