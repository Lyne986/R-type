/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ATransition.cpp
*/

#include "Transitions/ATransition.hpp"

namespace RT::Client::Transitions
{

    ATransition::ATransition()
    {
    }

    bool ATransition::getIsPlaying() const
    {
        return this->isPlaying;
    }

    float ATransition::lerp(float a, float b, float t)
    {
        return a + (b - a) * t;
    }
}