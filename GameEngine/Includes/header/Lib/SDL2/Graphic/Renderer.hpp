#ifndef __RT_GAMEENGINE_LIB_SDL2_RENDERER_HPP__
    #define __RT_GAMEENGINE_LIB_SDL2_RENDERER_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Lib/SDL2/Window/Window.hpp"
    #include "Utils/Error.hpp"

    #include <SDL.h>

class RT::GE::Lib::SDL2::Graphic::Renderer {
    private:
    SDL_Renderer *renderer;

    public:
    Renderer(Window::Window &window, int index, Uint32 flags);
    ~Renderer();
    SDL_Renderer *getRenderer();
    void render();
    bool clear(int r, int g, int b, int a);
};

#endif
