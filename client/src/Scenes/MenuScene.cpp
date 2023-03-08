#include "MenuScene.hpp"

namespace RT::Client::Scenes {

    MenuScene::MenuScene(GE::Lib::SDL2::Window::Event& event, GE::Lib::SDL2::Graphic::Renderer& renderer, std::string objectsPath)
        : AScene(event, renderer, objectsPath)
    {
        this->registerComponents();
        this->entityManager->init();
        RT::GE::ECS::Entity buttonGame = this->entityManager->getEntity("gameButton");
        RT::GE::ECS::Entity buttonOption = this->entityManager->getEntity("optionButton");
        RT::GE::ECS::Entity buttonQuit = this->entityManager->getEntity("quitButton");
        std::shared_ptr<RT::Client::Components::ButtonScene> clickGame = std::make_shared<RT::Client::Components::ButtonScene>("room", this, event);
        std::shared_ptr<RT::Client::Components::ButtonScene> clickOption = std::make_shared<RT::Client::Components::ButtonScene>("option", this, event);
        std::shared_ptr<RT::Client::Components::ButtonScene> clickQuit = std::make_shared<RT::Client::Components::ButtonScene>("quit", this, event);
        this->componentManager->addComponent<Components::ButtonScene>(buttonGame, clickGame);
        this->componentManager->addComponent<Components::ButtonScene>(buttonOption, clickOption);
        this->componentManager->addComponent<Components::ButtonScene>(buttonQuit, clickQuit);
        this->systemManager->addRenderSystem<RT::GE::ECS::Systems::RenderSystem>();

    }

    void MenuScene::registerComponents()
    {
        // this->systemManager.addLogicSystem<RT::Client::Systems::ClickButtonSceneSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::ReleaseButtonSceneSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::HoverButtonSceneSystem>();
        // this->systemManager->addLogicSystem<RT::Client::Systems::ClickButtonSceneSystem>();
        this->componentManager->registerComponent<Components::ButtonScene>();
    }

    void MenuScene::init()
    {
        this->systemManager->init(this->entityManager);
        this->parser->changeScene();
    }

    void MenuScene::update()
    {
        systemManager->updateLogic(this->entityManager);
    }

    void MenuScene::render()
    {
        renderer.clear(0, 0, 0, 255);
        systemManager->updateRender(this->entityManager);
        renderer.render();
    }
}
