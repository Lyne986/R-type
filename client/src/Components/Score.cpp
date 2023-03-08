/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Score.cpp
*/

#include "Components/Score.hpp"

namespace RT::Client::Components {

    Score::Score()
    {
        this->score = 0;
    }

    unsigned int Score::getScore() const
    {
        return this->score;
    }

    void Score::setScore(unsigned int score)
    {
        this->score = score;
    }

}