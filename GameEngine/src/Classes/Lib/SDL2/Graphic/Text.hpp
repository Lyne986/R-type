#ifndef __LIB_SDL2_TEXT_HPP__
    #define __LIB_SDL2_TEXT_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Lib/SDL2/Graphic/Renderer.hpp"
    #include "Lib/SDL2/Graphic/Rect.hpp"
    #include "Lib/SDL2/Graphic/Surface.hpp"
    #include "Lib/SDL2/Graphic/Texture.hpp"
    #include "Utils/Vector2.hpp"

    #include <SDL.h>
    #include <SDL_ttf.h>

class RT::GE::Lib::SDL2::Graphic::Text {

    private:
    Renderer &renderer;
    TTF_Font *font = NULL;
    std::unique_ptr<Surface> surface = NULL;
    std::unique_ptr<Texture> texture = NULL;
    SDL_Color color;
    Utils::Vector2<int> pos, dim;
    unsigned int size;
    std::string text;
    Rect drawRect;
    void update();

public:
    Text(
        Renderer &renderer,
        std::string text,
        Utils::Vector2<int> pos,
        unsigned int size,
        SDL_Color color={255, 255, 255, 255},
        std::string font="assets/font/arial.ttf"
    );
    ~Text();
    void draw();
    void setColor(SDL_Color color);
    void setColorAlpha(int alpha);
    SDL_Color getColor();
    void setText(std::string text);
    std::string getText();
    Utils::Vector2<int> getPos() const;
    void setPos(Utils::Vector2<int> pos);
    Utils::Vector2<int> getDim() const;

};

#endif
