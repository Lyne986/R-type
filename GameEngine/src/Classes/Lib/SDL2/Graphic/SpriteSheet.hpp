#ifndef __PA_LIB_SDL2_SPRITESHEET_HPP__
    #define __PA_LIB_SDL2_SPRITESHEET_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Lib/SDL2/Graphic/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Texture.hpp"
    #include "Lib/SDL2/Graphic/Rect.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Utils/Vector2.hpp"

    #include <SDL.h>


class RT::GE::Lib::SDL2::Graphic::SpriteSheet {

    private:
    Renderer &renderer;
    std::shared_ptr<Texture> texture;
    Utils::Vector2<int> srcPos = {0, 0}, srcDim = {0, 0};
    Rect src;
    Rect drawRect;
    Utils::Vector2<int> nbSprite = {0, 0};
    Utils::Vector2<int> pos = {0, 0};
    Utils::Vector2<int> dim = {0, 0};
    Utils::Vector2<int> currIndex = {0, 0};
    std::string name;

    public:
    SpriteSheet(
        Renderer &renderer,
        SpriteManager &spriteManager,
        std::string path,
        Utils::Vector2<int> nbSprite,
        Utils::Vector2<int> pos,
        Utils::Vector2<int> dim
    );
    void draw();
    void setIndex(Utils::Vector2<int> index);
    Utils::Vector2<int> getIndex() const;
    void setPos(Utils::Vector2<int> pos);
    Utils::Vector2<int> getPos() const;
    Utils::Vector2<int> getDim() const;
    std::string getName() const;

};

#endif
