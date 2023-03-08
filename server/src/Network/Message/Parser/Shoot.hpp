#ifndef __RT_SERVER_NETWORK_PARSER_SHOOT_HPP__
    #define __RT_SERVER_NETWORK_PARSER_SHOOT_HPP__

    #include "AParser.hpp"
    #include "Network/MyServer.hpp"
    #include "GameLogic/PartyManager.hpp"
    #include <GameEngineNetwork.hpp>
    #include <memory>

namespace RT::Server::Network::Message::Parser {
    class Shoot : public AParser {
        private:
            std::shared_ptr<GameLogic::PartyManager> partyManager = GameLogic::PartyManager::getInstance();

        public:
            Shoot(MyServer &server);
            void parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg);
    };
}

#endif