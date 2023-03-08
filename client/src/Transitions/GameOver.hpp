/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** GameOver.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_GAME_OVER_HPP__
    #define __RT_GE_ECS_COMPONENTS_GAME_OVER_HPP__

    #include "Transitions/ATransition.hpp"

class RT::Client::Transitions::GameOver
    : public RT::Client::Transitions::ATransition {

    private:
        enum State {
            FADE_IN,
            FADE_OUT,
            END
        };

        State currentState = State::FADE_IN;
        float currentLength;
        unsigned int alpha;
        std::shared_ptr<GE::ECS::Components::Text> cText;

    public:
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
};

#endif