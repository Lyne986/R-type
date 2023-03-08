/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ATransition.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_A_TRANSITION_HPP__
    #define __RT_GE_ECS_COMPONENTS_A_TRANSITION_HPP__

    #include "ClientNamespace.hpp"
    #include "Lib/SDL2/Timer.hpp"
    #include <GameEngineECS.hpp>
    #include <cmath>

class RT::Client::Transitions::ATransition {

    protected:
        bool isPlaying;
        unsigned int length;

        float lerp(float a, float b, float t);

    public:
        ATransition();
        ~ATransition(){};

        bool getIsPlaying() const;
        virtual void init(std::shared_ptr<GE::ECS::EntityManager> entityManager) = 0;
        virtual void update(std::shared_ptr<GE::ECS::EntityManager> entityManager) = 0;
};

#endif