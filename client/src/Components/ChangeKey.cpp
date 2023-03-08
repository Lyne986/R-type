#include "ChangeKey.hpp"

namespace RT   ::Client::Components {
    ChangeKey::ChangeKey(GE::Lib::SDL2::Window::Event &event, GE::Lib::SDL2::Window::Event::Action action)
    : AComponent("changekey"), action(action), event(event)
    {
        changeKey = false;
    }

    SDL_Scancode ChangeKey::modifyAction()
    {
        SDL_Scancode key = this->event.getEventKey();
        if (key == SDL_SCANCODE_UNKNOWN) 
            return SDL_SCANCODE_UNKNOWN;
        this->event.changeEventKey(this->action, key);
        this->changeKey = false;
        return key;
    }

    std::string ChangeKey::getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        if (this->changeKey) {
            SDL_Scancode key = this->modifyAction();
            if (key == SDL_SCANCODE_UNKNOWN)
                return "";
            if (this->action == GE::Lib::SDL2::Window::Event::Action::GoUp)
                return "Up: " +  std::string(SDL_GetScancodeName(key));
            if (this->action == GE::Lib::SDL2::Window::Event::Action::GoDown)
                return "Down: " + std::string(SDL_GetScancodeName(key));
            if (this->action == GE::Lib::SDL2::Window::Event::Action::GoLeft)
                return "Left: " + std::string(SDL_GetScancodeName(key));
            if (this->action == GE::Lib::SDL2::Window::Event::Action::GoRight)
                return "Right: " + std::string(SDL_GetScancodeName(key));
            if (this->action == GE::Lib::SDL2::Window::Event::Action::Shoot)
                return "Shoot: " + std::string(SDL_GetScancodeName(key));
            return "";
        }
        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                this->changeKey = true;
                return "Changing key...";
            }
        }
        return "";
    }
}
