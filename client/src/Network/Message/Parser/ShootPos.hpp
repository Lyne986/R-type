#ifndef __RT_CLIENT_NETWORK_MESSAGE_PARSER_PLAYER_SHOOT_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PARSER_PLAYER_SHOOT_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "Components/Damage.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineUtils.hpp>

namespace RT::Client::Network::Message::Parser {
    class ShootPos : public AParser {
        public:
            ShootPos(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };
}

#endif