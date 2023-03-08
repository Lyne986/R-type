#include "Lib/SDL2/SDL2.hpp"

namespace RT::GE::Lib::SDL2
{
    SDL2::SDL2()
    {
        if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
            throw Utils::Error("SDL_Init Error: " + std::string(SDL_GetError()));
        }
        if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
            throw Utils::Error("IMG_Init Error: " + std::string(IMG_GetError()));
        }
        if (TTF_Init() != 0) {
            throw Utils::Error("TTF_Init Error: " + std::string(TTF_GetError()));
        }
    }

    SDL2::~SDL2()
    {
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }
}
