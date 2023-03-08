#include "Scene/AScene.hpp"

namespace RT::GE::Scene {

    AScene::AScene(Lib::SDL2::Window::Event &event, Lib::SDL2::Graphic::Renderer &renderer, std::string objectsPath)
    : event(event), renderer(renderer)
    {
        this->systemManager = std::make_shared<ECS::SystemManager>();
        this->componentManager = std::make_shared<ECS::ComponentManager>();
        this->entityManager = std::make_shared<ECS::EntityManager>(*componentManager, renderer, spriteManager, objectsPath);
    }

    bool AScene::getChangeScene() const
    {
        return this->changeScene;
    }

    std::string AScene::getNextScene() const
    {
        return this->nextScene;
    }

    void AScene::setChangeScene(bool enabled)
    {
        this->changeScene = enabled;
    }

    void AScene::setNextScene(std::string nextScene)
    {
        this->nextScene = nextScene;
    }

    std::shared_ptr<ECS::EntityManager> AScene::getEntityManager()
    {
        return this->entityManager;
    }

}
