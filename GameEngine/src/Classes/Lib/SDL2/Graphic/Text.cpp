#include "Text.hpp"

namespace RT::GE::Lib::SDL2::Graphic {

    Text::Text(
        Renderer &renderer,
        std::string text, Utils::Vector2<int> pos, unsigned int size, SDL_Color color, std::string font
    ) : renderer(renderer), drawRect(pos.x, pos.y, size, size) {
        this->text = text;
        this->color = color;
        this->size = size;
        this->pos = pos;
        this->font = TTF_OpenFont(font.c_str(), this->size);
        this->update();
    }

    Text::~Text() {
        TTF_CloseFont(this->font);
    }

    void Text::update()
    {
        this->surface = std::make_unique<Surface>(TTF_RenderText_Blended(this->font, this->text.c_str(), this->color));
        this->texture = std::make_unique<Texture>(renderer, this->surface->getSurface());
    }

    void Text::draw() {
        this->dim = this->texture->getDim();
        this->drawRect.setRect(this->pos.x, this->pos.y, this->dim.x, this->dim.y);
        SDL_RenderCopy(this->renderer.getRenderer(), this->texture->getTexture(), NULL, &this->drawRect.getRect());
    }

    void Text::setText(std::string text) {
        this->text = text;
        this->update();
    }

    std::string Text::getText() {
        return this->text;
    }

    void Text::setColor(SDL_Color color) {
        this->color = color;
        this->update();
    }

    void Text::setColorAlpha(int alpha)
    {
        this->color.a = alpha;
        this->update();
    }

    SDL_Color Text::getColor() {
        return this->color;
    }

    Utils::Vector2<int> Text::getPos() const
    {
        return this->pos;
    }

    void Text::setPos(Utils::Vector2<int> pos) {
        this->pos = pos;
    }

    Utils::Vector2<int> Text::getDim() const
    {
        return this->dim;
    }

}
