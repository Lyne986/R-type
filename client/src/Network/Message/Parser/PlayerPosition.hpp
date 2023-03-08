#ifndef __RT_NETWORK_MESSAGE_PARSER_PLAYERPOSITION_HPP__
    #define __RT_NETWORK_MESSAGE_PARSER_PLAYERPOSITION_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "Components/OnlinePlayer.hpp"
    #include <GameEngineNetwork.hpp>
    #include <GameEngineUtils.hpp>

namespace RT::Client::Network::Message::Parser {
    class PlayerPosition : public AParser {
        public:
            PlayerPosition(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };
}

#endif