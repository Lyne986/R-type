#ifndef __RT_GE_ECS_COMPONENTS_BUTTON_HPP__
#define __RT_GE_ECS_COMPONENTS_BUTTON_HPP__

#include "ClientNamespace.hpp"
#include "ECSNamespace.hpp"
#include <GameEngineECS.hpp>
#include <GameEngineScene.hpp>
#include <GameEngineWindow.hpp>

class RT::Client::Components::ButtonScene
    : public RT::GE::ECS::Components::AComponent {

private:
    std::string newScene;
    RT::GE::Scene::AScene *scene;
    GE::Lib::SDL2::Window::Event &event;

public:
    ButtonScene(std::string newScene, RT::GE::Scene::AScene *scene, GE::Lib::SDL2::Window::Event &event);
    ~ButtonScene() {};

    void onClick();
    void getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
    bool getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
    bool getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);

    bool getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);
};

#endif
