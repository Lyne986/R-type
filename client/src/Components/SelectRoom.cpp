/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** SelectRoom
*/

#include "SelectRoom.hpp"

namespace RT::Client::Components {
    SelectRoom::SelectRoom(int id, GE::Lib::SDL2::Window::Event &event)
    : AComponent("selectRoom"), event(event)
    {
        _id = id;
    }

    void SelectRoom::onClick()
    {
        this->_isSelected = true;
        _IdInstance->setId(_id);
    }

    bool SelectRoom::getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            return true;
        }
        return false;
    }

    void SelectRoom::getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (mousePos.x >= pos.x && mousePos.x <= pos.x + dim.x && mousePos.y >= pos.y && mousePos.y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                this->onClick();
            }
        }
    }

    bool SelectRoom::getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                return true;
            }
        }
        return false;
    }

    bool SelectRoom::getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isMouseRelease()) {
                return true;
            }
        }
        return false;
    }

    bool SelectRoom::isSelect() const
    {
        return _isSelected;
    }

    int SelectRoom::getId() const
    {
        return _id;
    }

    void SelectRoom::setSelect(bool statut)
    {
        _isSelected = statut;
    }
}
