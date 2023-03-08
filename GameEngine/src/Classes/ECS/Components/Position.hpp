/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Position.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_POSITION_HPP__
    #define __RT_GE_ECS_COMPONENTS_POSITION_HPP__

    #include "ECSNamespace.hpp"
    #include "Utils/Vector2.hpp"
    #include "ECS/Components/AComponent.hpp"

class RT::GE::ECS::Components::Position
 : public RT::GE::ECS::Components::AComponent {

    private:
    Utils::Vector2<float> pos;

    public:
    Position(Utils::Vector2<float> pos);
    Position(float x, float y);
    Position();
    ~Position() {};

    Utils::Vector2<float> &get();
    void set(Utils::Vector2<float> pos);
};

#endif