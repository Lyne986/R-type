/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** HealthSystem.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_HEALTH_SYSTEM_HPP__
    #define __RT_GE_ECS_COMPONENTS_HEALTH_SYSTEM_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include <GameEngineECS.hpp>
    #include "Components/Health.hpp"
    #include "Components/Damage.hpp"
    #include "Components/Score.hpp"
    #include "Components/Enemy.hpp"
    #include "Components/HealthUI.hpp"
    #include "Components/MainPlayer.hpp"
    #include "Utils/Debug/Log.hpp"

class RT::Client::Systems::HealthSystem
 : public RT::GE::ECS::Systems::ASystem {

    private:
        void destroyEntity(std::shared_ptr<GE::ECS::EntityManager> entityManager, GE::ECS::Entity entity);
        void updateUI(GE::ECS::ComponentManager &componentManager);

    public:
        ~HealthSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);

};

#endif