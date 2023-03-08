#ifndef __RT_GE_NETWORK_MESSAGE_PARSER_JOINMESSAGE_HPP__
    #define __RT_GE_NETWORK_MESSAGE_PARSER_JOINMESSAGE_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "Components/MainPlayer.hpp"
    #include <memory>
    #include <GameEngineNetwork.hpp>
    #include <GameEngineECS.hpp>
    #include <GameEngineScene.hpp>

namespace RT::Client::Network::Message::Parser {
    
    class JoinMessage : public AParser {
        public:
            JoinMessage(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };

}

#endif