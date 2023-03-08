/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** System.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_ASYSTEM_HPP__
    #define __RT_GAMEENGINE_ECS_ASYSTEM_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/ComponentManager.hpp"

class RT::GE::ECS::Systems::ASystem {

    public:
        ASystem();
        virtual void init(std::shared_ptr<EntityManager> entityManager) = 0;
        virtual void update(std::shared_ptr<EntityManager> entityManager) = 0;
};

#endif