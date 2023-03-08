#include "Network/Message/Parser/PlayerWin.hpp"

namespace RT::Client::Network::Message::Parser {

    PlayerWin::PlayerWin(std::shared_ptr<GE::Scene::SceneManager> sceneManager)
    : AParser(sceneManager)
    {
    }

    void PlayerWin::parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg)
    {
        RT::GE::Network::Message::PlayerWon_s playerWon;
        msg >> playerWon;

        std::shared_ptr<GE::Scene::AScene> scene = sceneManager->getCurr();
        std::shared_ptr<RT::Client::Scenes::GameScene> gameScene = std::dynamic_pointer_cast<RT::Client::Scenes::GameScene>(scene);
        if (gameScene) {
            gameScene->setServerHasWon(true);
        }
    }

}