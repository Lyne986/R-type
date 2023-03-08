/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Text.cpp
*/

#include "ECS/Components/Text.hpp"

namespace RT::GE::ECS::Components {

    Text::Text(
        Lib::SDL2::Graphic::Renderer &renderer,
        std::string text,
        Utils::Vector2<int> pos,
        unsigned int size,
        unsigned int layer,
        SDL_Color color,
        std::string font
    ) : text(renderer, text, pos, size, color, font), ADrawable(ADrawable::Text, layer) {

    }

    void Text::draw()
    {
        this->text.draw();
    }

    Utils::Vector2<int> Text::getPos() const
    {
        return this->text.getPos();
    }

    void Text::setPos(Utils::Vector2<int> newPos)
    {
        this->text.setPos(newPos);
    }

    Utils::Vector2<int> Text::getDim() const
    {
        return this->text.getDim();
    }

    void Text::setText(std::string newText)
    {
        this->text.setText(newText);
    }

    Lib::SDL2::Graphic::Text &Text::getText()
    {
        return this->text;
    }
}
