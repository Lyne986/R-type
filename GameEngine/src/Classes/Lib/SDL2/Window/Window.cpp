#include "Window.hpp"

namespace RT::GE::Lib::SDL2::Window {

    Window::Window(std::string title, int x, int y, int w, int h)
    {
        this->window = SDL_CreateWindow(title.c_str(), x, y, w, h, SDL_WINDOW_SHOWN);
        if (this->window == nullptr) {
            throw Utils::Error("SDL_CreateWindow Error: " + std::string(SDL_GetError()));
        }
    }

    Window::~Window()
    {
        SDL_DestroyWindow(this->window);
    }

    SDL_Window *Window::getWindow()
    {
        return (this->window);
    }

};