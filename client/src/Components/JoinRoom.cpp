/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** JoinRoom
*/

#include "JoinRoom.hpp"

namespace RT::Client::Components {
    JoinRoom::JoinRoom(std::string name, GE::Lib::SDL2::Window::Event &event, std::string newScene, RT::GE::Scene::AScene *scene)
    : AComponent("JoinRoom"), event(event)
    {
        this->scene = scene;
        this->newScene = newScene;
    }

    void JoinRoom::onClick()
    {
    }

    void JoinRoom::onRelease()
    {
        GE::Network::Message::JoinRoom joinRoom(_IdInstance->getId());
        message_s<CustomMsgTypes> msg("JoinRoom");
        msg.header.id = CustomMsgTypes::JoinRoom;

        msg << joinRoom;

        _client->send(msg);
        this->scene->setNextScene(this->newScene);
        this->scene->setChangeScene(true);
    }

    bool JoinRoom::getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            return true;
        }
        return false;
    }

    void JoinRoom::getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (mousePos.x >= pos.x && mousePos.x <= pos.x + dim.x && mousePos.y >= pos.y && mousePos.y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                this->onClick();
            }
        }
    }

    bool JoinRoom::getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                return true;
            }
        }
        return false;
    }

    bool JoinRoom::getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
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

    void JoinRoom::setRoomId(int id)
    {
        _RoomId = id;
    }
}
