/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** AnimationSystem.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_ANIMATION_SYSTEM_HPP__
    #define __RT_GAMEENGINE_ECS_ANIMATION_SYSTEM_HPP__

    #include "ASystem.hpp"
    #include "ECS/EntityManager.hpp"
    #include "Lib/SDL2/Timer.hpp"

class RT::GE::ECS::Systems::AnimationSystem : public ASystem {

    public:
        AnimationSystem() {};
        void init(std::shared_ptr<EntityManager> entityManager);
        void update(std::shared_ptr<EntityManager> entityManager);
};

#endif