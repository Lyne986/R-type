/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** CreateRoom
*/

#include "CreateRoom.hpp"

namespace RT::Client::Components {
    CreateRoom::CreateRoom(std::string name, GE::Lib::SDL2::Window::Event &event)
    : AComponent("createRoom"), event(event)
    {
        _name = name;
    }

    void CreateRoom::onClick()
    {
    }

    void CreateRoom::onRelease()
    {
        GE::Network::Message::CreateRoom createRoom(_name);
        message_s<CustomMsgTypes> msg("CreateRoom");
        msg.header.id = CustomMsgTypes::CreateRoom;

        msg << createRoom;

        _client->send(msg);

        
    }


    bool CreateRoom::getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            return true;
        }
        return false;
    }

    void CreateRoom::getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (mousePos.x >= pos.x && mousePos.x <= pos.x + dim.x && mousePos.y >= pos.y && mousePos.y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                this->onClick();
            }
        }
    }

    bool CreateRoom::getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                return true;
            }
        }
        return false;
    }

    bool CreateRoom::getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isMouseRelease()) {
                this->onRelease();
                return true;
            }
        }
        return false;
    }
}
