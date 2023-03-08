#ifndef __RT_CLIENT_NETWORK_MESSAGE_PARSER_UDPINIT_HPP__
    #define __RT_CLIENT_NETWORK_MESSAGE_PARSER_UDPINIT_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/AParser.hpp"
    #include "Network/SingletonClient.hpp"
    #include <GameEngineNetwork.hpp>
    #include <GameEngineScene.hpp>
    #include <memory>

namespace RT::Client::Network::Message::Parser {
    class UDPInit : public AParser {
        private:
            std::shared_ptr<GE::Network::Client::Client> client = SingletonClient::getInstance();

        public:
            UDPInit(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
    };
}

#endif