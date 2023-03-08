/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Position.cpp
*/

#include "ECS/Components/Position.hpp"

namespace RT::GE::ECS::Components {

    Position::Position(Utils::Vector2<float> pos)
    : pos(pos), AComponent("position") {};

    Position::Position(float x, float y)
    : pos(x, y), AComponent("position") {};

    Position::Position()
    : pos(0, 0), AComponent("position") {};

    Utils::Vector2<float> &Position::get() {
        return (this->pos);
    }

    void Position::set(Utils::Vector2<float> pos) {
        this->pos = pos;
    }

}