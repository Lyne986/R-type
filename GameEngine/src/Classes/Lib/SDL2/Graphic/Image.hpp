#ifndef __LIB_SDL2_IMAGE_HPP__
    #define __LIB_SDL2_IMAGE_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Lib/SDL2/Graphic/Renderer.hpp"
    #include "Lib/SDL2/Window/Event.hpp"
    #include "Lib/SDL2/Graphic/Texture.hpp"
    #include "Lib/SDL2/Graphic/Rect.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Utils/Vector2.hpp"

    #include <SDL.h>
    #include <SDL_image.h>

    #include <string>
    #include <memory>

class RT::GE::Lib::SDL2::Graphic::Image {
    private:
    Window::Event &event;
    Renderer &renderer;
    std::string path;
    Rect drawRect;
    std::unique_ptr<Texture> texture;
    Utils::Vector2<int> pos = {0, 0}, dim = {0, 0};
    Utils::Vector2<int> srcDim = {0, 0};

    public:
    Image(
        Window::Event &event,
        Renderer &renderer,
        SpriteManager &spriteManager,
        std::string path,
        Utils::Vector2<int> dim,
        Utils::Vector2<int> pos={0, 0}
    );
    bool draw();
    void setPosition(Utils::Vector2<int> pos);
    void setDimensions(Utils::Vector2<int> dim);
    Utils::Vector2<int> getPosition();
    Utils::Vector2<int> getDimensions();
    void move(Utils::Vector2<int> pos);
    bool isClick();
    bool isClickOutside();
};

#endif
