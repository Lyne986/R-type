/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** RenderSystem.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_RENDERSYSTEM_HPP__
    #define __RT_GAMEENGINE_ECS_RENDERSYSTEM_HPP__

    #include "ASystem.hpp"
    #include "ECS/EntityManager.hpp"
    #include <cmath>
    #include <map>
    #include <vector>

class RT::GE::ECS::Systems::RenderSystem : public ASystem {
    public:
        RenderSystem() {};
        void init(std::shared_ptr<EntityManager> entityManager);
        void update(std::shared_ptr<EntityManager> entityManager);
};

#endif