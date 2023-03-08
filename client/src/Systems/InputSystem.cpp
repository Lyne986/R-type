/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** InputSystem.cpp
*/

#include "Systems/InputSystem.hpp"

namespace RT::Client::Systems {

    void InputSystem::init(std::shared_ptr<GE::ECS::EntityManager>)
    {

    }

    void InputSystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        static GE::Lib::SDL2::Timer physicsTimer;
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> players = componentManager.getComponents<GE::ECS::Components::Input>();

        physicsTimer.tick();
        this->currentFiringCooldown += physicsTimer.getElapsedSeconds();
        for (auto &player : players) {
            std::shared_ptr<GE::ECS::Components::Velocity> cVelocity = componentManager.getComponent<GE::ECS::Components::Velocity>(player.first);
            std::shared_ptr<GE::ECS::Components::Input> cInput = std::dynamic_pointer_cast<GE::ECS::Components::Input>(player.second);
            GE::Lib::SDL2::Window::Event &event = cInput->get();
            GE::Utils::Vector2<float> &velocity = cVelocity->get();

            this->updatePlayerPosition(event, velocity);
            this->updatePlayerFire(entityManager, player.first, event);
        }
    }

    void InputSystem::updatePlayerPosition(GE::Lib::SDL2::Window::Event &event, GE::Utils::Vector2<float> &velocity)
    {
        if (event.isActionKeyPressed(GE::Lib::SDL2::Window::Event::Action::GoLeft)) {
            velocity.x = -1;
        } else if (event.isActionKeyPressed(GE::Lib::SDL2::Window::Event::Action::GoRight)) {
            velocity.x = 1;
        }

        if (event.isActionKeyReleased(GE::Lib::SDL2::Window::Event::Action::GoLeft) || event.isActionKeyReleased(GE::Lib::SDL2::Window::Event::Action::GoRight)) {
            velocity.x = 0;
        }

        if (event.isActionKeyPressed(GE::Lib::SDL2::Window::Event::Action::GoUp)) {
            velocity.y = -1;
        } else if (event.isActionKeyPressed(GE::Lib::SDL2::Window::Event::Action::GoDown)) {
            velocity.y = 1;
        }

        if (event.isActionKeyReleased(GE::Lib::SDL2::Window::Event::Action::GoUp) || event.isActionKeyReleased(GE::Lib::SDL2::Window::Event::Action::GoDown)) {
            velocity.y = 0;
        }
    }

    void InputSystem::updatePlayerFire(std::shared_ptr<GE::ECS::EntityManager> entityManager, GE::ECS::Entity player, GE::Lib::SDL2::Window::Event &event)
    {
        if (!this->isFiring && event.isActionKeyPressed(GE::Lib::SDL2::Window::Event::Action::Shoot)) {
            this->isFiring = true;

            if (this->currentFiringCooldown > this->firingCooldown) {
                this->currentFiringCooldown = 0;
                this->shootBullet(entityManager, player);
            }
        }

        if (event.isActionKeyReleased(GE::Lib::SDL2::Window::Event::Action::Shoot)) {
            this->isFiring = false;
        }
    }

    void InputSystem::sendShootToServer(std::shared_ptr<GE::ECS::EntityManager> entityManager, std::shared_ptr<GE::ECS::Components::Position> bulletPosition)
    {
        message_s<CustomMsgTypes> msg("ShootPos");
        msg.header.id = CustomMsgTypes::ServerMessage;
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        auto mainPlayer = componentManager.getComponents<Components::MainPlayer>();
        for (auto &player : mainPlayer) {
            std::shared_ptr<Components::MainPlayer> cMainPlayer = std::dynamic_pointer_cast<Components::MainPlayer>(player.second);
            GE::Network::Message::ShootPos shoot;
            shoot.pid = cMainPlayer->getPid();
            shoot.x = bulletPosition->get().x;
            shoot.y = bulletPosition->get().y;
            shoot.gid = this->_IdInstance->getId();
            msg << shoot;
            this->client->sendUDP(msg);

            GE::Network::Message::Shoot shootMsg(cMainPlayer->getPid(), 1);
            message_s<CustomMsgTypes> msg("Shoot");
            msg.header.id = CustomMsgTypes::ServerMessage;
            msg << shootMsg;
            this->client->send(msg);
        }
    }

    void InputSystem::shootBullet(std::shared_ptr<GE::ECS::EntityManager> entityManager, GE::ECS::Entity player)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        GE::ECS::Entity bullet = entityManager->createEntity("assets/objects/prefabs/bullet.json");
        std::shared_ptr<GE::ECS::Components::Position> bulletPosition = componentManager.getComponent<GE::ECS::Components::Position>(bullet);
        std::shared_ptr<GE::ECS::Components::Collider> bulletCollider = componentManager.getComponent<GE::ECS::Components::Collider>(bullet);
        std::shared_ptr<GE::ECS::Components::Position> playerPosition = componentManager.getComponent<GE::ECS::Components::Position>(player);
        std::shared_ptr<GE::ECS::Components::Collider> playerCollider = componentManager.getComponent<GE::ECS::Components::Collider>(player);
        std::shared_ptr<GE::ECS::Components::Animation> playerAnimation = componentManager.getComponent<GE::ECS::Components::Animation>(player);

        bulletCollider->addIgnoringEntity(player);
        playerCollider->addIgnoringEntity(bullet);
        bulletPosition->set(bulletPosition->get() + playerPosition->get());
        GE::Utils::Debug::Log::LogMessage(GE::Utils::Debug::Log::Player, "Missile fired!");
        this->sendShootToServer(entityManager, bulletPosition);
        GE::ECS::AudioManager::getInstance()->getSound("playerShot")->play();
        if (playerAnimation != nullptr && playerAnimation->hasAnim("shoot")) {
            playerAnimation->setCurrentAnim("shoot");
        }
    }
}
