/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Health.cpp
*/

#include "Health.hpp"

namespace RT::Client::Components {
    Health::Health(unsigned int health, float invincibleTime) : AComponent("health")
    {
        this->health = health;
        this->maxHealth = health;
        this->invincibleTime = invincibleTime;
        this->currentInvincibleTime = 0;
    }

    unsigned int Health::getHealth() const
    {
        return this->health;
    }

    void Health::damage(unsigned int damage)
    {
        this->updateStatus();
        if (!this->isInvincible) {
            if (damage >= this->health) {
                this->health = 0;
            } else {
                this->health -= damage;
            }
        }
    }

    void Health::heal(unsigned int amount)
    {
        if (this->health + amount >= this->maxHealth) {
            this->health = this->maxHealth;
        } else {
            this->health += amount;
        }
    }

    void Health::updateStatus()
    {
        static GE::Lib::SDL2::Timer timer;
        timer.tick();
        float elapsedSeconds = timer.getElapsedSeconds();

        if (elapsedSeconds <=  this->invincibleTime) {
            this->isInvincible = true;
        } else {
            this->isInvincible = false;
        }
    }

}