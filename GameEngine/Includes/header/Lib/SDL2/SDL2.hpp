#ifndef __RT_GAMEENGINE_SDL2_SDL2_HPP__
    #define __RT_GAMEENGINE_SDL2_SDL2_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Utils/Error.hpp"
    #include <string>

    #include <SDL.h>
    #include <SDL_image.h>
    #include <SDL_ttf.h>
    #include <SDL_mixer.h>


class RT::GE::Lib::SDL2::SDL2 {
    public:
        SDL2();
        ~SDL2();
};

#endif
