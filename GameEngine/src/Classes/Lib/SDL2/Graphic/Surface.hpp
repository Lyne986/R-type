#ifndef __PA_LIB_SDL2_GRAPHIC_SURFACE_HPP__
    #define __PA_LIB_SDL2_GRAPHIC_SURFACE_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Error.hpp"
    #include <string>

    #include <SDL.h>
    #include <SDL_image.h>
    

class RT::GE::Lib::SDL2::Graphic::Surface {

    private:
    SDL_Surface *surface;

    public:
    Surface(std::string path);
    Surface(SDL_Surface *surface);
    ~Surface();
    SDL_Surface *getSurface();
    Utils::Vector2<int> getDim();

};

#endif
