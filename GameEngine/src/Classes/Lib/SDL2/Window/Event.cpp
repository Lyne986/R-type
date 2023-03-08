#include "Lib/SDL2/Window/Event.hpp"

namespace RT::GE::Lib::SDL2::Window {

    Event::Event() {
        this->event = SDL_Event();
        this->isQuitEvent = false;
        this->changeKeys.push_back(SDL_SCANCODE_UP);
        this->changeKeys.push_back(SDL_SCANCODE_DOWN);
        this->changeKeys.push_back(SDL_SCANCODE_LEFT);
        this->changeKeys.push_back(SDL_SCANCODE_RIGHT);
        this->changeKeys.push_back(SDL_SCANCODE_SPACE);
    }

    void Event::poll() {
        this->isClickEvent = false;
        while (SDL_PollEvent(&this->event)) {
            if (this->event.type == SDL_QUIT) {
                this->isQuitEvent = true;
            }
            if (this->event.type == SDL_MOUSEBUTTONDOWN) {
                this->isClickEvent = true;
                this->clickPosition = {this->event.button.x, this->event.button.y};
                if (this->event.button.button == SDL_BUTTON_LEFT) {
                    this->mouseButton = 1;
                } else if (this->event.button.button == SDL_BUTTON_RIGHT) {
                    this->mouseButton = 2;
                }
            } else {
                this->mouseButton = 0;
            }
            this->events.push_back(event);
        }
    }

    void Event::clear()
    {
        this->events.clear();
    }

    void Event::printPoll()
    {
        if (this->events.size() > 0) {
            Utils::Debug::Log::LogMessage(GE::Utils::Debug::Log::Event, "Number of events: " + this->events.size());
            for (int i = 0; i < this->events.size(); i++) {
                Utils::Debug::Log::LogMessage(GE::Utils::Debug::Log::Event, "Event type: " + this->events[i].type);
            }
        }
    }

    void Event::changeEventKey(Action action, SDL_Scancode key)
    {
        this->changeKeys[action] = key;
    }

    bool Event::isQuit() {
        return (this->isQuitEvent);
    }

    bool Event::isClick() {
        return (this->isClickEvent);
    }

    Utils::Vector2<int> Event::getClickPosition() {
        return (this->clickPosition);
    }

    Utils::Vector2<int> Event::getMousePosition() {
        int x, y;
        SDL_GetMouseState(&x, &y);
        return (Utils::Vector2<int>{x, y});
    }

    bool Event::isMouseRelease() {
        for (int i = 0; i < this->events.size(); i++) {
            if (this->events[i].type == SDL_MOUSEBUTTONUP) {
                return true;
            }
        }
        return false;
    }

    bool Event::isKeyPressed(SDL_Scancode key) {
        for (int i = 0; i < this->events.size(); i++) {
            if (this->events[i].type == SDL_KEYDOWN && this->events[i].key.keysym.scancode == key) {
                // // std::cout << "Key pressed : " << key << std::endl;
                return true;
            }
        }
        return false;
    }

    bool Event::isKeyReleased(SDL_Scancode key) {
        for (int i = 0; i < this->events.size(); i++) {
            if (this->events[i].type == SDL_KEYUP && this->events[i].key.keysym.scancode == key) {
                return true;
            }
        }
        return false;
    }

    bool Event::isActionKeyPressed(Action action) {
        // // std::cout << "Action key pressed : " << this->changeKeys[action] << std::endl;
        return this->isKeyPressed(this->changeKeys[action]);
    }

    bool Event::isActionKeyReleased(Action action) {
        return this->isKeyReleased(this->changeKeys[action]);
    }

    bool Event::isRightClick() {
        return this->mouseButton == 2;
    }

    bool Event::isLeftClick() {
        return this->mouseButton == 1;
    }

    SDL_Scancode Event::getEventKey() const {
        for (int i = 0; i < this->events.size(); i++) {
            if (this->events[i].type == SDL_KEYDOWN) {
                return this->events[i].key.keysym.scancode;
            }
        }
        return SDL_SCANCODE_UNKNOWN;
    }
}
