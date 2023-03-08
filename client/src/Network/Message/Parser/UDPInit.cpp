#include "Network/Message/Parser/UDPInit.hpp"

namespace RT::Client::Network::Message::Parser {

    UDPInit::UDPInit(std::shared_ptr<GE::Scene::SceneManager> sceneManager)
    : AParser(sceneManager) {

    }

    void UDPInit::parse(std::shared_ptr<RT::GE::Network::Client::Client>, message_s<CustomMsgTypes> msg)
    {
        GE::Network::Message::UDPInit info;
        msg >> info;
        int port = info.port;
        // std::cout << "PORT received: " << port << std::endl;
        this->client->connectUdp("127.0.0.1", port);
    }
}