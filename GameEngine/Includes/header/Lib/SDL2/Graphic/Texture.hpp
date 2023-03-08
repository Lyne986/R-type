#ifndef __PA_LIB_SDL2_GRAPHIC_TEXTURE_HPP__
    #define __PA_LIB_SDL2_GRAPHIC_TEXTURE_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Lib/SDL2/Graphic/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Surface.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Utils/Vector2.hpp"

    #include <SDL.h>


class RT::GE::Lib::SDL2::Graphic::Texture {

    private:
    SDL_Texture *texture;


    public:
    Texture(Renderer &renderer, SpriteManager &spriteManager, std::string path);
    Texture(Renderer &renderer, SDL_Surface *surface);
    Texture(SDL_Texture *texture);
    ~Texture();
    SDL_Texture *getTexture();
    Utils::Vector2<int> getDim();

};

#endif
