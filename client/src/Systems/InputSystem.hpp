/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** InputSystem.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_INPUT_SYSTEM_HPP__
    #define __RT_GE_ECS_COMPONENTS_INPUT_SYSTEM_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include "ECS/EntityManager.hpp"
    #include "ECS/SystemManager.hpp"
    #include "ECS/Components/Input.hpp"
    #include "Components/Damage.hpp"
    #include "Components/MainPlayer.hpp"
    #include "Lib/SDL2/Window/Event.hpp"
    #include "Lib/SDL2/Timer.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Network/SingletonClient.hpp"
    #include "Components/SingletonIdRoom.hpp"
    #include <GameEngineECS.hpp>

class RT::Client::Systems::InputSystem
 : public RT::GE::ECS::Systems::ASystem {

    private:
        bool isFiring = false;
        float firingCooldown = 0.4f;
        float currentFiringCooldown = 0.0f;
        std::shared_ptr<GE::Network::Client::Client> client = Network::SingletonClient::getInstance();
        std::shared_ptr<SingletonIdRoom> _IdInstance = SingletonIdRoom::getInstance();

    public:
        ~InputSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void updatePlayerPosition(GE::Lib::SDL2::Window::Event &event, GE::Utils::Vector2<float> &velocity);
        void updatePlayerCollision(RT::GE::ECS::Entity playerEntity, GE::Utils::Vector2<float> &velocity, GE::ECS::ComponentManager &componentManager);
        void updatePlayerFire(std::shared_ptr<GE::ECS::EntityManager> entityManager, GE::ECS::Entity player, GE::Lib::SDL2::Window::Event &event);
        void shootBullet(std::shared_ptr<GE::ECS::EntityManager> entityManager, GE::ECS::Entity player);
        void sendShootToServer(std::shared_ptr<GE::ECS::EntityManager> entityManager, std::shared_ptr<GE::ECS::Components::Position> bulletPosition);
};

#endif