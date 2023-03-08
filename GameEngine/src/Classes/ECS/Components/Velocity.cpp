/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Velocity.cpp
*/

#include "Velocity.hpp"

namespace RT::GE::ECS::Components {

    Velocity::Velocity(Utils::Vector2<float> velocity)
    : velocity(velocity), AComponent("velocity") {};

    Velocity::Velocity(float x, float y)
    : velocity(x, y), AComponent("velocity") {};

    Velocity::Velocity()
    : velocity(0, 0), AComponent("velocity") {};

    Utils::Vector2<float> &Velocity::get() {
        return (this->velocity);
    }

    void Velocity::set(Utils::Vector2<float> velocity) {
        this->velocity = velocity;
    }

}