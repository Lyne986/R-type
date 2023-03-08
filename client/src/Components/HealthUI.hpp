/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** HealthUI.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_HEALTH_UI_HPP__
    #define __RT_GE_ECS_COMPONENTS_HEALTH_UI_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"

class RT::Client::Components::HealthUI
: public RT::GE::ECS::Components::AComponent {

    private:
        unsigned int health;

    public:
        HealthUI();
        ~HealthUI() {};

        unsigned int getHealth() const;
        void setHealth(unsigned int health);
};

#endif