#ifndef __RT_CLIENT_NETWORK_MESSAGE_PARSER_SPAWN_ENEMY_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PARSER_SPAWN_ENEMY_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include <memory>
    #include <iostream>
    #include <GameEngineECS.hpp>
    #include <GameEngineUtils.hpp>
    #include <GameEngineNetwork.hpp>

namespace RT::Client::Network::Message::Parser {
    class SpawnEnemy : public AParser {
        public:
            SpawnEnemy(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };
}

#endif