/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** MovementSystem.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_MOVEMENTSYSTEM_HPP__
    #define __RT_GAMEENGINE_ECS_MOVEMENTSYSTEM_HPP__

    #include "ASystem.hpp"
    #include "ECS/EntityManager.hpp"
    #include "Lib/SDL2/Timer.hpp"

class RT::GE::ECS::Systems::MovementSystem : public ASystem {

    public:
        MovementSystem() {};
        void init(std::shared_ptr<EntityManager> entityManager);
        void update(std::shared_ptr<EntityManager> entityManager);
};

#endif