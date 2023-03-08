#ifndef __LIB_SDL2_SPRITE_MANAGER_HPP__
    #define __LIB_SDL2_SPRITE_MANAGER_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Lib/SDL2/Graphic/Surface.hpp"
    #include <unordered_map>
    #include <string>
    #include <memory>

    #include <SDL.h>
    #include <SDL_image.h>

class RT::GE::Lib::SDL2::Graphic::SpriteManager {

    private:
    std::unordered_map<std::string, std::shared_ptr<Surface>> sprites;

    public:
    SpriteManager();
    std::shared_ptr<Surface> getSprite(std::string path);

};

#endif
