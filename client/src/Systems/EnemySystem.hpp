/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** EnemySystem.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_ENEMY_SYSTEM_HPP__
    #define __RT_GE_ECS_COMPONENTS_ENEMY_SYSTEM_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include "ECS/EntityManager.hpp"
    #include "ECS/SystemManager.hpp"
    #include "Components/Enemy.hpp"
    #include "ECS/Components/Velocity.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Lib/SDL2/Timer.hpp"

class RT::Client::Systems::EnemySystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~EnemySystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void shootBullet(std::shared_ptr<GE::ECS::EntityManager> entityManager, GE::ECS::Entity enemy, std::string bulletPath);
};

#endif