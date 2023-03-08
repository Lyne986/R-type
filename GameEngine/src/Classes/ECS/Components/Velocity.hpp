/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Velocity.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_VELOCITY_HPP__
    #define __RT_GE_ECS_COMPONENTS_VELOCITY_HPP__

    #include "ECSNamespace.hpp"
    #include "Utils/Vector2.hpp"
    #include "ECS/Components/AComponent.hpp"

class RT::GE::ECS::Components::Velocity
 : public RT::GE::ECS::Components::AComponent {

    private:
    Utils::Vector2<float> velocity;

    public:
    Velocity(Utils::Vector2<float> velocity);
    Velocity(float x, float y);
    Velocity();
    ~Velocity() {};

    Utils::Vector2<float> &get();
    void set(Utils::Vector2<float> velocity);
};

#endif