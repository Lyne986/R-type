/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Damage.cpp
*/

#include "Damage.hpp"

namespace RT::Client::Components {
    Damage::Damage(unsigned int damage, bool destroyOnCollision): AComponent("damage")
    {
        this->damage = damage;
        this->destroyOnCollision = destroyOnCollision;
    }

    unsigned int Damage::getDamage() const
    {
        return this->damage;
    }

    bool Damage::getDestroyOnCollision() const
    {
        return this->destroyOnCollision;
    }

}