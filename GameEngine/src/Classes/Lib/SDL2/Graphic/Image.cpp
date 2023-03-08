#include "Lib/SDL2/Graphic/Image.hpp"

namespace RT::GE::Lib::SDL2::Graphic {

    Image::Image(
        Window::Event &event, Renderer &renderer, SpriteManager &spriteManager,
        std::string path, Utils::Vector2<int> dim, Utils::Vector2<int> pos
    ) : event(event), renderer(renderer), drawRect(pos.x, pos.y, dim.x, dim.y) {
        this->path = path;
        this->texture = std::make_unique<Texture>(renderer, spriteManager, path);
        this->dim = dim;
        this->pos = pos;
    }

    bool Image::draw() {
        this->drawRect.setRect(this->pos.x, this->pos.y, this->dim.x, this->dim.y);
        return (SDL_RenderCopy(this->renderer.getRenderer(), this->texture->getTexture(), NULL, &this->drawRect.getRect()) == 0);
    }

    void Image::setPosition(Utils::Vector2<int> pos) {
        this->pos = pos;
    }

    void Image::setDimensions(Utils::Vector2<int> dim) {
        this->dim = dim;
    }

    Utils::Vector2<int> Image::getPosition() {
        return (this->pos);
    }

    Utils::Vector2<int> Image::getDimensions() {
        return (this->dim);
    }

    void Image::move(Utils::Vector2<int> pos) {
        this->pos.x += pos.x;
        this->pos.y += pos.y;
    }

    bool Image::isClick() {
        if (this->event.isClick()) {
            Utils::Vector2<int> mousePos = this->event.getClickPosition();
            if (mousePos.x >= this->pos.x && mousePos.x <= this->pos.x + this->dim.x) {
                if (mousePos.y >= this->pos.y && mousePos.y <= this->pos.y + this->dim.y) {
                    return (true);
                }
            }
        }
        return (false);
    }

    bool Image::isClickOutside() {
        if (this->event.isClick()) {
            Utils::Vector2<int> mousePos = this->event.getClickPosition();
            if (mousePos.x < this->pos.x || mousePos.x > this->pos.x + this->dim.x) {
                return (true);
            }
            if (mousePos.y < this->pos.y || mousePos.y > this->pos.y + this->dim.y) {
                return (true);
            }
        }
        return (false);
    }

}
