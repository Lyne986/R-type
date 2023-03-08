#ifndef __RT_CLIENT_NETWORK_MESSAGE_PARSER_APARSER_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PARSER_APARSER_HPP__

    #include "NetworkNamespace.hpp"
    #include "IParser.hpp"
    #include "Components/OnlinePlayer.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineScene.hpp>

namespace RT::Client::Network::Message::Parser {
    class AParser : public IParser {
        protected:
            std::shared_ptr<GE::ECS::EntityManager> entityManager;
            std::shared_ptr<GE::Scene::SceneManager> sceneManager;

        public:
            AParser(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            virtual void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg) = 0;
            void updateScene();
    };
}

#endif