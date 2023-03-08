#ifndef __RT_GAMEENGINE_LIB_SDL2_EVENT_HPP__
    #define __RT_GAMEENGINE_LIB_SDL2_EVENT_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Debug/Log.hpp"
    #include <vector>

    #include <SDL.h>
    


class RT::GE::Lib::SDL2::Window::Event {
    private:
    SDL_Event event;
    bool isQuitEvent = false;
    bool isClickEvent = false;
    Utils::Vector2<int> clickPosition = {0, 0};
    std::vector<SDL_Event> events;
    std::vector<SDL_Scancode> changeKeys;
    int mouseButton = 0;

    public:
    enum Action {
        GoUp,
        GoDown,
        GoLeft,
        GoRight,
        Shoot
    };
    Event();
    void poll();
    void clear();
    void printPoll();
    void changeEventKey(Action action, SDL_Scancode key);
    bool isQuit();
    bool isClick();
    bool isRightClick();
    bool isLeftClick();
    bool isMouseRelease();
    bool isKeyPressed(SDL_Scancode key);
    bool isKeyReleased(SDL_Scancode key);
    bool isActionKeyPressed(Action action);
    bool isActionKeyReleased(Action action);
    Utils::Vector2<int> getClickPosition();
    Utils::Vector2<int> getMousePosition();
    SDL_Scancode getEventKey() const;
};

#endif
