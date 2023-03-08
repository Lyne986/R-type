#ifndef __RT_CLIENT_NETWORK_MESSAGE_PLAYERDISCONNECT_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PLAYERDISCONNECT_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include <GameEngineNetwork.hpp>
    #include <GameEngineECS.hpp>

namespace RT::Client::Network::Message::Parser {
    class PlayerDisconnect : public AParser {
        public:
            PlayerDisconnect(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };
}

#endif