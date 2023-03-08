/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Score.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_SCORE_HPP__
    #define __RT_GE_ECS_COMPONENTS_SCORE_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"

class RT::Client::Components::Score
: public RT::GE::ECS::Components::AComponent {

    private:
        unsigned int score;

    public:
        Score();
        ~Score() {};

        unsigned int getScore() const;
        void setScore(unsigned int score);
};

#endif