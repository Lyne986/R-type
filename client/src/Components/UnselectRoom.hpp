/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** UnselectRoom
*/

#ifndef UNSELECTROOM_HPP_
#define UNSELECTROOM_HPP_

#include "ClientNamespace.hpp"
#include "ECSNamespace.hpp"
#include <GameEngineECS.hpp>
#include <GameEngineScene.hpp>
#include <GameEngineWindow.hpp>
#include "SingletonIdRoom.hpp"

class RT::Client::Components::UnselectRoom
    : public RT::GE::ECS::Components::AComponent {
    public:
        UnselectRoom(std::string name, GE::Lib::SDL2::Window::Event &event);
        ~UnselectRoom() {};

        void onClick();
        void getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);

    private:
        GE::Lib::SDL2::Window::Event &event;
        std::shared_ptr<SingletonIdRoom> _IdInstance = SingletonIdRoom::getInstance();
};

#endif /* !UnselectRoom_HPP_ */
