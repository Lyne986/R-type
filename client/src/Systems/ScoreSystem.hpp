/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ScoreSystem.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_GAME_UI_SYSTEM_HPP__
    #define __RT_GE_ECS_COMPONENTS_GAME_UI_SYSTEM_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include "ECS/EntityManager.hpp"
    #include "ECS/SystemManager.hpp"
    #include "Components/Score.hpp"
    #include "Utils/Debug/Log.hpp"

class RT::Client::Systems::ScoreSystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~ScoreSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);

};

#endif