#include "Scenes/GameScene.hpp"

namespace RT::Client::Scenes
{

    GameScene::GameScene(GE::Lib::SDL2::Window::Event &event, GE::Lib::SDL2::Graphic::Renderer &renderer, std::string objectsPath, std::string levelPath)
        : AScene(event, renderer, objectsPath), levelPath(levelPath), objectsPath(objectsPath)
    {
        this->registerSystems();

        GE::ECS::AudioManager::getInstance()->addMusic("gameTheme", "assets/audio/02-Solo-Sortie.mp3");
        GE::ECS::AudioManager::getInstance()->addSound("playerShot", "assets/audio/playerShot.ogg");
        GE::ECS::AudioManager::getInstance()->addSound("objectDeath", "assets/audio/objectDeath.ogg");

        this->gameStartTransition = std::make_unique<Transitions::GameStart>();
        this->gameOverTransition = std::make_unique<Transitions::GameOver>();
        this->gameWonTransition = std::make_unique<Transitions::GameWon>();
    }

    void GameScene::registerSystems()
    {
        this->systemManager->addLogicSystem<RT::Client::Systems::InputSystem>();
        this->systemManager->addLogicSystem<RT::GE::ECS::Systems::CollisionSystem>();
        this->systemManager->addLogicSystem<RT::GE::ECS::Systems::MovementSystem>();
        this->systemManager->addLogicSystem<RT::GE::ECS::Systems::ParallaxSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::HealthSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::MainPlayer>();
        this->systemManager->addLogicSystem<Systems::OnlinePlayer>();
        this->systemManager->addLogicSystem<RT::Client::Systems::EnemySystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::ScoreSystem>();
        this->systemManager->addLogicSystem<RT::GE::ECS::Systems::AnimationSystem>();

        this->systemManager->addRenderSystem<RT::GE::ECS::Systems::RenderSystem>();
    }

    void GameScene::init()
    {
        this->gameOver = false;
        this->localOver = false;
        this->hasWon = false;
        this->serverHasWon = false;
        // this->spawnManager = std::make_unique<SpawnManager>(this->levelPath);
        this->componentManager = std::make_shared<RT::GE::ECS::ComponentManager>();
        this->entityManager = std::make_shared<RT::GE::ECS::EntityManager>(*this->componentManager, this->renderer, this->spriteManager, this->objectsPath);

        this->registerComponents();
        this->entityManager->init();

        RT::GE::ECS::Entity playerSpaceship = this->entityManager->getEntity("playerSpaceship");
        std::shared_ptr<RT::GE::ECS::Components::Input> input = std::make_shared<RT::GE::ECS::Components::Input>(event);
        this->componentManager->addComponent<RT::GE::ECS::Components::Input>(playerSpaceship, input);

        systemManager->init(this->entityManager);
        this->gameStartTransition->init(this->entityManager);
        this->gameOverTransition->init(this->entityManager);
        this->gameWonTransition->init(this->entityManager);
        GE::ECS::AudioManager::getInstance()->getMusic("gameTheme")->play(-1);
    }

    void GameScene::registerComponents()
    {
        this->componentManager->registerComponent<Components::OnlinePlayer>();
        this->entityManager->registerFunction([this](RT::GE::ECS::Entity entity, nlohmann::json data) {
            if (data["onlinePlayer"] != nullptr && data["onlinePlayer"] == true) {
                Client::Components::OnlinePlayer onlinePlayer;
                this->componentManager->addComponent<Client::Components::OnlinePlayer>(entity, onlinePlayer);
            }
        });

        this->componentManager->registerComponent<Components::MainPlayer>();
        this->entityManager->registerFunction([this](GE::ECS::Entity entity, nlohmann::json data) {
            if (data["player"] != nullptr && data["player"] == true) {
                Client::Components::MainPlayer mainPlayer;
                this->componentManager->addComponent<Client::Components::MainPlayer>(entity, mainPlayer);
            } });

        this->componentManager->registerComponent<Components::Health>();
        this->entityManager->registerFunction([this](GE::ECS::Entity entity, nlohmann::json data) {
            if (data["health"] != nullptr) {
                float invincibleTime = (data["health"]["invincibleTime"] != nullptr) ? (float)data["health"]["invincibleTime"] : 0.0f;
                Client::Components::Health health(data["health"]["value"], invincibleTime);
                this->componentManager->addComponent<Client::Components::Health>(entity, health);
            } });
        this->componentManager->registerComponent<Components::Damage>();
        this->entityManager->registerFunction([this](GE::ECS::Entity entity, nlohmann::json data) {
            if (data["damage"] != nullptr) {
                Client::Components::Damage damage(data["damage"]["value"], data["damage"]["destroyOnCollide"]);
                this->componentManager->addComponent<Client::Components::Damage>(entity, damage);
            } });

        this->componentManager->registerComponent<Components::Enemy>();
        this->entityManager->registerFunction([this](GE::ECS::Entity entity, nlohmann::json data) {
            if (data["enemy"] != nullptr) {
                Client::Components::Enemy enemy(data["enemy"]);
                this->componentManager->addComponent<Client::Components::Enemy>(entity, enemy);
            } });

        this->componentManager->registerComponent<Components::Score>();
        this->entityManager->registerFunction([this](GE::ECS::Entity entity, nlohmann::json data) {
            if (data["score"] != nullptr) {
                Client::Components::Score score;
                this->componentManager->addComponent<Client::Components::Score>(entity, score);
            } });

        this->componentManager->registerComponent<Components::HealthUI>();
        this->entityManager->registerFunction([this](GE::ECS::Entity entity, nlohmann::json data) {
            if (data["healthUI"] != nullptr) {
                Client::Components::HealthUI health;
                this->componentManager->addComponent<Client::Components::HealthUI>(entity, health);
            } });
    }

    void GameScene::update()
    {
        this->checkGameOver();
        this->checkGameWon();
        if (this->hasWon) {
            if (this->gameWonTransition->getIsPlaying()) {
                this->gameWonTransition->update(this->entityManager);
            } else {
                this->setNextScene("menu");
                this->setChangeScene(true);
            }
        } else if (this->gameOver) {
            if (this->gameOverTransition->getIsPlaying()) {
                this->gameOverTransition->update(this->entityManager);
            } else {
                this->setNextScene("menu");
                this->setChangeScene(true);
            }
        } else {
            if (this->gameStartTransition->getIsPlaying()) {
                this->gameStartTransition->update(this->entityManager);
            } else {
                // spawnManager->update(this->entityManager);
            }
            systemManager->updateLogic(this->entityManager);
        }
    }

    void GameScene::checkGameOver()
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> mainPlayers = componentManager.getComponents<Components::MainPlayer>();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> onlinePlayers = componentManager.getComponents<Components::OnlinePlayer>();
        static int mainPlayerPid = -1;

        if (mainPlayers.size() == 0) {
            this->gameOver = true;
            GE::Network::Message::PlayerDisconnect playerDisconnect(mainPlayerPid);
            message_s<CustomMsgTypes> msg("PlayerDisconnect");
            msg << playerDisconnect;
            this->client->send(msg);
            if (onlinePlayers.size() == 0) {
                this->gameOver = true;
            }
        } else {
            std::shared_ptr<Components::MainPlayer> mainPlayer = std::static_pointer_cast<Components::MainPlayer>(mainPlayers.begin()->second);
            mainPlayerPid = mainPlayer->getPid();
        }
    }

    void GameScene::checkGameWon()
    {
        if (this->serverHasWon) {
            GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
            std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> enemies = componentManager.getComponents<Components::Enemy>();

            if (enemies.size() == 0) {
                this->hasWon = true;
                std::cout << "You won" << std::endl;
            }
        }
    }

    void GameScene::render()
    {
        renderer.clear(0, 0, 0, 255);
        systemManager->updateRender(this->entityManager);
        renderer.render();
    }

    void GameScene::setServerHasWon(bool hasWon)
    {
        this->serverHasWon = hasWon;
    }

}
