/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Text.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_TEXT_HPP__
    #define __RT_GE_ECS_COMPONENTS_TEXT_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/Components/ADrawable.hpp"
    #include "Lib/SDL2/Graphic/Text.hpp"

class RT::GE::ECS::Components::Text
: public RT::GE::ECS::Components::ADrawable {

    private:
        Lib::SDL2::Graphic::Text text;

    public:
        Text(
            Lib::SDL2::Graphic::Renderer &renderer,
            std::string text,
            Utils::Vector2<int> pos,
            unsigned int size,
            unsigned int layer,
            SDL_Color color={255, 255, 255, 255},
            std::string font="assets/font/arial.ttf"
        );
        ~Text() {};

        void draw();
        Utils::Vector2<int> getPos() const;
        void setPos(Utils::Vector2<int> newPos);
        Utils::Vector2<int> getDim() const;
        void setText(std::string newText);
        Lib::SDL2::Graphic::Text &getText();

};

#endif
