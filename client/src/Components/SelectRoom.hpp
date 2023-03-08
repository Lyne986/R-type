/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** SelectRoom
*/

#ifndef SELECTROOM_HPP_
#define SELECTROOM_HPP_

#include "ClientNamespace.hpp"
#include "ECSNamespace.hpp"
#include <GameEngineECS.hpp>
#include <GameEngineScene.hpp>
#include <GameEngineWindow.hpp>
#include "SingletonIdRoom.hpp"


class RT::Client::Components::SelectRoom
    : public RT::GE::ECS::Components::AComponent {
    public:
        SelectRoom(int id, GE::Lib::SDL2::Window::Event &event);
        ~SelectRoom() {};

        void onClick();
        void getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool isSelect() const;
        int getId() const;
        void setSelect(bool statut);

    private:
        GE::Lib::SDL2::Window::Event &event;
        bool _isSelected = false;
        int _id;
        std::shared_ptr<SingletonIdRoom> _IdInstance = SingletonIdRoom::getInstance();
};

#endif /* !SelectRoom_HPP_ */
