/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ADrawable.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_ADRAWABLE_HPP__
    #define __RT_GE_ECS_COMPONENTS_ADRAWABLE_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"
    #include "Utils/Vector2.hpp"

class RT::GE::ECS::Components::ADrawable
: public RT::GE::ECS::Components::AComponent {

    public:
        enum DrawableType {
            Text,
            Spritesheet
        };

        ADrawable(
            DrawableType type,
            unsigned int layer
        );
        ~ADrawable() {};

        DrawableType getType() const;
        unsigned int getLayer() const;
        void setVisible(bool visible);
        bool isVisible() const;

        virtual void draw() = 0;
        virtual Utils::Vector2<int> getPos() const = 0;
        virtual void setPos(Utils::Vector2<int> newPos) = 0;
        virtual Utils::Vector2<int> getDim() const = 0;

    protected:
        unsigned int layer;
        bool visible = true;
        DrawableType type;

};

#endif