/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Health.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_HEALTH_HPP__
    #define __RT_GE_ECS_COMPONENTS_HEALTH_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"
    #include "Lib/SDL2/Timer.hpp"

class RT::Client::Components::Health
: public RT::GE::ECS::Components::AComponent {

    private:
        unsigned int health;
        unsigned int maxHealth;
        bool isInvincible;
        float invincibleTime;
        float currentInvincibleTime;

    public:
        Health(unsigned int health, float invincibleTime);
        ~Health() {};

        unsigned int getHealth() const;
        void damage(unsigned int damage);
        void heal(unsigned int amount);
        void updateStatus();
};

#endif