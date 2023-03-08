/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** UnselectRoom
*/

#include "UnselectRoom.hpp"

namespace RT::Client::Components {
    UnselectRoom::UnselectRoom(std::string name, GE::Lib::SDL2::Window::Event &event)
    : AComponent("unselectRoom"), event(event)
    {
    }

    void UnselectRoom::onClick()
    {
        _IdInstance->setId(-1);
    }


    bool UnselectRoom::getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            return true;
        }
        return false;
    }

    void UnselectRoom::getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (mousePos.x >= pos.x && mousePos.x <= pos.x + dim.x && mousePos.y >= pos.y && mousePos.y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                this->onClick();
            }
        }
    }

    bool UnselectRoom::getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                return true;
            }
        }
        return false;
    }

    bool UnselectRoom::getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isMouseRelease()) {
                return true;
            }
        }
        return false;
    }
}
