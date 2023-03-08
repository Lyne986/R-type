#ifndef __RT_GAMEENGINE_LIB_SDL2_WINDOW_HPP__
    #define __RT_GAMEENGINE_LIB_SDL2_WINDOW_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Utils/Error.hpp"

    #include <SDL.h>

class RT::GE::Lib::SDL2::Window::Window {
    private:
    SDL_Window *window;

    public:
    Window(std::string title, int x, int y, int w, int h);
    ~Window();
    SDL_Window *getWindow();
};

#endif
