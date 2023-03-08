/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** JoinRoom
*/

#ifndef JOINROOM_HPP_
#define JOINROOM_HPP_

#include "ClientNamespace.hpp"
#include "ECSNamespace.hpp"
#include <GameEngineECS.hpp>
#include <GameEngineScene.hpp>
#include <GameEngineWindow.hpp>
#include "Network/SingletonClient.hpp"
#include "SingletonIdRoom.hpp"

class RT::Client::Components::JoinRoom
    : public RT::GE::ECS::Components::AComponent {
    public:
        JoinRoom(std::string name, GE::Lib::SDL2::Window::Event &event, std::string newScene, RT::GE::Scene::AScene *scene);
        ~JoinRoom() {};

        void onClick();
        void onRelease();
        void getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        void setRoomId(int id);

    private:
        GE::Lib::SDL2::Window::Event &event;
        std::shared_ptr<RT::GE::Network::Client::Client> _client = Network::SingletonClient::getInstance();
        int _RoomId;
        std::shared_ptr<SingletonIdRoom> _IdInstance = SingletonIdRoom::getInstance();
        std::string newScene;
        RT::GE::Scene::AScene *scene;
};

#endif /* !JoinRoom_HPP_ */
