#ifndef __RT_GE_ECS_COMPONENTS_CHANGEKEY_HPP__
#define __RT_GE_ECS_COMPONENTS_CHANGEKEY_HPP__

#include "ClientNamespace.hpp"
#include "ECSNamespace.hpp"
#include <GameEngineECS.hpp>
#include <GameEngineScene.hpp>
#include <GameEngineWindow.hpp>

class RT::Client::Components::ChangeKey
    : public RT::GE::ECS::Components::AComponent {

private:
    bool changeKey;
    GE::Lib::SDL2::Window::Event::Action action;
    GE::Lib::SDL2::Window::Event &event;

public:
    ChangeKey(GE::Lib::SDL2::Window::Event &event, GE::Lib::SDL2::Window::Event::Action action);
    ~ChangeKey() {};
    SDL_Scancode modifyAction();
    std::string getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
};

#endif
