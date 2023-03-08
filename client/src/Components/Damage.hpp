/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Damage.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_DAMAGE_HPP__
    #define __RT_GE_ECS_COMPONENTS_DAMAGE_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"

class RT::Client::Components::Damage
: public RT::GE::ECS::Components::AComponent {

    private:
        unsigned int damage;
        bool destroyOnCollision;

    public:
        Damage(unsigned int damage, bool destroyOnCollision);
        ~Damage() {};

        unsigned int getDamage() const;
        bool getDestroyOnCollision() const;
};

#endif