#include "Lib/SDL2/Graphic/Renderer.hpp"

namespace RT::GE::Lib::SDL2::Graphic {

    Renderer::Renderer(Window::Window &window, int index, Uint32 flags)
    {
        this->renderer = SDL_CreateRenderer(window.getWindow(), index, flags);
        SDL_SetRenderDrawBlendMode(this->renderer, SDL_BLENDMODE_BLEND);
        if (this->renderer == nullptr) {
            throw Utils::Error("SDL_CreateRenderer Error: " + std::string(SDL_GetError()));
        }
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(this->renderer);
    }

    SDL_Renderer *Renderer::getRenderer()
    {
        return (this->renderer);
    }

    void Renderer::render()
    {
        SDL_RenderPresent(this->renderer);
    }

    bool Renderer::clear(int r, int g, int b, int a)
    {
        if (SDL_SetRenderDrawColor(this->renderer, r, g, b, a) != 0) {
            throw Utils::Error("SDL_SetRenderDrawColor Error: " + std::string(SDL_GetError()));
            return (false);
        } else if (SDL_RenderClear(this->renderer) != 0) {
            throw Utils::Error("SDL_RenderClear Error: " + std::string(SDL_GetError()));
            return (false);
        }
        return (true);
    }
}
