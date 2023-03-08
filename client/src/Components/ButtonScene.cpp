#include "ButtonScene.hpp"

namespace RT::Client::Components {
    ButtonScene::ButtonScene(std::string newScene, RT::GE::Scene::AScene *scene, GE::Lib::SDL2::Window::Event &event)
    : AComponent("buttonscene"), event(event)
    {
        this->scene = scene;
        this->newScene = newScene;
    }

    void ButtonScene::onClick()
    {
        if (this->newScene == "quit") {
            exit(0);
        }
        if (this->newScene == "") {
            return;
        }
        this->scene->setNextScene(this->newScene);
        this->scene->setChangeScene(true);
    }

    bool ButtonScene::getHover(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (mousePos.x >= pos.x && mousePos.x <= pos.x + dim.x && mousePos.y >= pos.y && mousePos.y <= pos.y + dim.y) {
            return true;
        }
        return false;
    }

    void ButtonScene::getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (mousePos.x >= pos.x && mousePos.x <= pos.x + dim.x && mousePos.y >= pos.y && mousePos.y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                this->onClick();
            }
        }
    }

    bool ButtonScene::getClickMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (mousePos.x >= pos.x && mousePos.x <= pos.x + dim.x && mousePos.y >= pos.y && mousePos.y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                return true;
            }
        }
        return false;
    }

    bool ButtonScene::getReleaseMenu(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        GE::Utils::Vector2<int> mousePos = this->event.getMousePosition();

        if (mousePos.x >= pos.x && mousePos.x <= pos.x + dim.x && mousePos.y >= pos.y && mousePos.y <= pos.y + dim.y) {
            if (this->event.isMouseRelease()) {
                return true;
            }
        }
        return false;
    }
}
