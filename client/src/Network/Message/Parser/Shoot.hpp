#ifndef __RT_CLIENT_NETWORK_MESSAGE_PARSER_SHOOT_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PARSER_SHOOT_HPP__

    #include "AParser.hpp"
    #include "NetworkNamespace.hpp"
    #include "Components/OnlinePlayer.hpp"
    #include <GameEngineNetwork.hpp>
    #include <GameEngineUtils.hpp>
    #include <GameEngineScene.hpp>
    #include <memory>

namespace RT::Client::Network::Message::Parser {
    class Shoot : public AParser {
        private:
            void launchAnimation(RT::GE::Network::Message::Shoot_s shoot);

        public:
            Shoot(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };
}

#endif