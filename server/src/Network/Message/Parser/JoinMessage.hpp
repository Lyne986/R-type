#ifndef __RT_GE_NETWORK_MESSAGE_PARSER_JOINMESSAGE_HPP__
    #define __RT_GE_NETWORK_MESSAGE_PARSER_JOINMESSAGE_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "GameLogic/PartyManager.hpp"
    #include "GameLogic/Party.hpp"
    #include <memory>
    #include <GameEngineNetwork.hpp>

namespace RT::Server::Network::Message::Parser {
    
    class JoinMessage : public AParser {
        public:
            JoinMessage(MyServer &server);
            void parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes> &msg);

        private:
            std::shared_ptr<GameLogic::PartyManager> partyManager = GameLogic::PartyManager::getInstance();
    };

}

#endif