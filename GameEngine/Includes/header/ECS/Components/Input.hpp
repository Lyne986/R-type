/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Input.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_INPUT_HPP__
    #define __RT_GE_ECS_COMPONENTS_INPUT_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"
    #include "Lib/SDL2/Window/Event.hpp"

class RT::GE::ECS::Components::Input
 : public RT::GE::ECS::Components::AComponent {

    private:
        Lib::SDL2::Window::Event &event;

    public:
        Input(Lib::SDL2::Window::Event &event);
        ~Input();
        Lib::SDL2::Window::Event &get() const;
};

#endif