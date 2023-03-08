/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** CreateRoom
*/

#ifndef CREATEROOM_HPP_
#define CREATEROOM_HPP_

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineScene.hpp>
    #include <GameEngineWindow.hpp>
    #include "Network/SingletonClient.hpp"

    #include <GameEngineUtils.hpp>
    #include <GameEngineNetwork.hpp>

class RT::Client::Components::CreateRoom
    : public RT::GE::ECS::Components::AComponent {
    public:
        CreateRoom(std::string name, GE::Lib::SDL2::Window::Event &event);
        ~CreateRoom() {};

        void onClick();
        void onRelease();
        void getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
        bool getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);

    private:
        GE::Lib::SDL2::Window::Event &event;
        bool isClicked = false;
        std::shared_ptr<RT::GE::Network::Client::Client> _client = Network::SingletonClient::getInstance();
        std::string _name;
};

#endif /* !CREATEROOM_HPP_ */
