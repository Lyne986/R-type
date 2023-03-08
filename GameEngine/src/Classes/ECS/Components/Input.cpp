/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Input.cpp
*/

#include "Input.hpp"

namespace RT::GE::ECS::Components {
    Input::Input(Lib::SDL2::Window::Event &event): event(event)
    {

    }

    Input::~Input()
    {

    }

    Lib::SDL2::Window::Event &Input::get() const
    {
        return this->event;
    }
}