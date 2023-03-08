#include "Network/Message/Parser/AParser.hpp"

namespace RT::Client::Network::Message::Parser {

    AParser::AParser(std::shared_ptr<GE::Scene::SceneManager> sceneManager)
    {
        this->sceneManager = sceneManager;
        std::shared_ptr<GE::Scene::AScene> scene = this->sceneManager->getCurr();
        if (scene != nullptr) {
            this->entityManager = scene->getEntityManager();
        }
    }

    void AParser::updateScene()
    {
        this->entityManager = this->sceneManager->getCurr()->getEntityManager();
    }

}
 