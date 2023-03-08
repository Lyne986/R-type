#include "OptionScene.hpp"

namespace RT::Client::Scenes {

    OptionScene::OptionScene(GE::Lib::SDL2::Window::Event& event, GE::Lib::SDL2::Graphic::Renderer& renderer, std::string objectsPath)
        : AScene(event, renderer, objectsPath)
    {
        this->registerComponents();
        this->entityManager->init();
        RT::GE::ECS::Entity buttonGame = this->entityManager->getEntity("menuButton");
        RT::GE::ECS::Entity GoDownKey = this->entityManager->getEntity("GoDownKey");
        RT::GE::ECS::Entity GoDownKeyImg = this->entityManager->getEntity("GoDownKeyImg");
        RT::GE::ECS::Entity GoUpKey = this->entityManager->getEntity("GoUpKey");
        RT::GE::ECS::Entity GoUpKeyImg = this->entityManager->getEntity("GoUpKeyImg");
        RT::GE::ECS::Entity GoLeftKey = this->entityManager->getEntity("GoLeftKey");
        RT::GE::ECS::Entity GoLeftKeyImg = this->entityManager->getEntity("GoLeftKeyImg");
        RT::GE::ECS::Entity GoRightKey = this->entityManager->getEntity("GoRightKey");
        RT::GE::ECS::Entity GoRightKeyImg = this->entityManager->getEntity("GoRightKeyImg");
        RT::GE::ECS::Entity ShootKey = this->entityManager->getEntity("ShootKey");
        RT::GE::ECS::Entity GoShootKeyImg = this->entityManager->getEntity("GoShootKeyImg");
        RT::GE::ECS::Entity moinsMusic = this->entityManager->getEntity("moinsMusic");
        RT::GE::ECS::Entity plusMusic = this->entityManager->getEntity("plusMusic");
        std::shared_ptr<RT::Client::Components::ButtonScene> clickGame = std::make_shared<RT::Client::Components::ButtonScene>("menu", this, event);
        std::shared_ptr<RT::Client::Components::ButtonScene> clickDownKeyImg = std::make_shared<RT::Client::Components::ButtonScene>("", this, event);
        std::shared_ptr<RT::Client::Components::ButtonScene> clickUpKeyImg = std::make_shared<RT::Client::Components::ButtonScene>("", this, event);
        std::shared_ptr<RT::Client::Components::ButtonScene> clickLeftKeyImg = std::make_shared<RT::Client::Components::ButtonScene>("", this, event);
        std::shared_ptr<RT::Client::Components::ButtonScene> clickRightKeyImg = std::make_shared<RT::Client::Components::ButtonScene>("", this, event);
        std::shared_ptr<RT::Client::Components::ButtonScene> clickShootKeyImg = std::make_shared<RT::Client::Components::ButtonScene>("", this, event);
        std::shared_ptr<RT::Client::Components::ChangeKey> changeKeyUp = std::make_shared<RT::Client::Components::ChangeKey>(event, GE::Lib::SDL2::Window::Event::Action::GoUp);
        std::shared_ptr<RT::Client::Components::ChangeKey> changeKeyDown = std::make_shared<RT::Client::Components::ChangeKey>(event, GE::Lib::SDL2::Window::Event::Action::GoDown);
        std::shared_ptr<RT::Client::Components::ChangeKey> changeKeyLeft = std::make_shared<RT::Client::Components::ChangeKey>(event, GE::Lib::SDL2::Window::Event::Action::GoLeft);
        std::shared_ptr<RT::Client::Components::ChangeKey> changeKeyRight = std::make_shared<RT::Client::Components::ChangeKey>(event, GE::Lib::SDL2::Window::Event::Action::GoRight);
        std::shared_ptr<RT::Client::Components::ChangeKey> changeKeyShoot = std::make_shared<RT::Client::Components::ChangeKey>(event, GE::Lib::SDL2::Window::Event::Action::Shoot);
        this->componentManager->addComponent<Components::ButtonScene>(buttonGame, clickGame);
        this->componentManager->addComponent<Components::ButtonScene>(GoUpKeyImg, clickDownKeyImg);
        this->componentManager->addComponent<Components::ButtonScene>(GoDownKeyImg, clickDownKeyImg);
        this->componentManager->addComponent<Components::ButtonScene>(GoLeftKeyImg, clickLeftKeyImg);
        this->componentManager->addComponent<Components::ButtonScene>(GoRightKeyImg, clickRightKeyImg);
        this->componentManager->addComponent<Components::ButtonScene>(GoShootKeyImg, clickShootKeyImg);

        std::shared_ptr<RT::Client::Components::ButtonSound> moinsMusicButton = std::make_shared<RT::Client::Components::ButtonSound>(RT::Client::Components::ButtonSound::SoundType::MUSIC, -2, event);
        std::shared_ptr<RT::Client::Components::ButtonSound> plusMusicButton = std::make_shared<RT::Client::Components::ButtonSound>(RT::Client::Components::ButtonSound::SoundType::MUSIC, 2, event);
        this->componentManager->addComponent<Components::ChangeKey>(GoUpKey, changeKeyUp);
        this->componentManager->addComponent<Components::ChangeKey>(GoDownKey, changeKeyDown);
        this->componentManager->addComponent<Components::ChangeKey>(GoLeftKey, changeKeyLeft);
        this->componentManager->addComponent<Components::ChangeKey>(GoRightKey, changeKeyRight);
        this->componentManager->addComponent<Components::ChangeKey>(ShootKey, changeKeyShoot);
        this->componentManager->addComponent<Components::ButtonSound>(moinsMusic, moinsMusicButton);
        this->componentManager->addComponent<Components::ButtonSound>(plusMusic, plusMusicButton);
        this->systemManager->addRenderSystem<RT::GE::ECS::Systems::RenderSystem>();
        GE::ECS::AudioManager::getInstance()->addMusic("optionTheme", "assets/audio/02-Solo-Sortie.mp3");
    }


    void OptionScene::registerComponents()
    {
        this->systemManager->addLogicSystem<RT::Client::Systems::ReleaseButtonSceneSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::HoverButtonSceneSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::ChangeKeySystem>();
        this->componentManager->registerComponent<Components::ButtonScene>();
        this->componentManager->registerComponent<Components::ChangeKey>();
        this->systemManager->addLogicSystem<RT::Client::Systems::ClickButtonSceneSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::ChangeSoundSystem>();
        this->componentManager->registerComponent<Components::ButtonSound>();
    }

    void OptionScene::init()
    {
        systemManager->init(this->entityManager);
        GE::ECS::AudioManager::getInstance()->getMusic("optionTheme")->play(-1);
    }

    void OptionScene::update()
    {
        systemManager->updateLogic(this->entityManager);
    }

    void OptionScene::render()
    {
        renderer.clear(0, 0, 0, 255);
        systemManager->updateRender(this->entityManager);
        renderer.render();
    }
}
