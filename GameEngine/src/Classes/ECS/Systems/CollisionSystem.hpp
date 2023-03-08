/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** CollisionSystem.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_COLLISIONSYSTEM_HPP__
    #define __RT_GAMEENGINE_ECS_COLLISIONSYSTEM_HPP__

    #include "ASystem.hpp"
    #include "ECS/EntityManager.hpp"
    #include "Lib/SDL2/Timer.hpp"
    #include <unordered_map>
    #include "Utils/Debug/Log.hpp"

class RT::GE::ECS::Systems::CollisionSystem : public ASystem {

    public:
        CollisionSystem() {};
        void init(std::shared_ptr<EntityManager> entityManager);
        void update(std::shared_ptr<EntityManager> entityManager);
};

#endif