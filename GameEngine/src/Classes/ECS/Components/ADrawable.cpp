/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ADrawable.cpp
*/

#include "ECS/Components/ADrawable.hpp"

namespace RT::GE::ECS::Components {

    ADrawable::ADrawable(
        DrawableType type,
        unsigned int layer
    ) : AComponent("ADrawable") {
        this->layer = layer;
        this->type = type;
    }

    ADrawable::DrawableType ADrawable::getType() const
    {
        return this->type;
    }

    unsigned int ADrawable::getLayer() const
    {
        return this->layer;
    }

    void ADrawable::setVisible(bool visible) {
        this->visible = visible;
    }

    bool ADrawable::isVisible() const {
        return (this->visible);
    }

}