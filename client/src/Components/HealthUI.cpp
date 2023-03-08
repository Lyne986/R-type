/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** HealthUI.cpp
*/

#include "Components/HealthUI.hpp"

namespace RT::Client::Components {

    HealthUI::HealthUI()
    {
        this->health = 0;
    }

    unsigned int HealthUI::getHealth() const
    {
        return this->health;
    }

    void HealthUI::setHealth(unsigned int health)
    {
        this->health = health;
    }

}