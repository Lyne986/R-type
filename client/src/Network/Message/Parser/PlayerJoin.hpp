#ifndef __RT_CLIENT_NETWORK_MESSAGE_PARSER_PLAYERJOIN_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PARSER_PLAYERJOIN_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "Components/OnlinePlayer.hpp"
    #include <GameEngineNetwork.hpp>

namespace RT::Client::Network::Message::Parser {

    class PlayerJoin : public AParser {
        public:
            PlayerJoin(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };

}

#endif