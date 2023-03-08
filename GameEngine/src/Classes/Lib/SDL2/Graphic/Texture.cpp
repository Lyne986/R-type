#include "Lib/SDL2/Graphic/Texture.hpp"

namespace RT::GE::Lib::SDL2::Graphic {

    Texture::Texture(Renderer &renderer, SpriteManager &spriteManager, std::string path) {
        std::shared_ptr<Graphic::Surface> surface = spriteManager.getSprite(path);
        this->texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface->getSurface());
    }

    Texture::Texture(Renderer &renderer, SDL_Surface *surface)
    {
        this->texture = SDL_CreateTextureFromSurface(renderer.getRenderer(), surface);
    }

    Texture::Texture(SDL_Texture *texture) {
        this->texture = texture;
    }

    Texture::~Texture() {
        if (this->texture) {
            SDL_DestroyTexture(this->texture);
        }
    }

    SDL_Texture *Texture::getTexture() {
        return (this->texture);
    }

    Utils::Vector2<int> Texture::getDim() {
        Utils::Vector2<int> dim;
        SDL_QueryTexture(this->texture, NULL, NULL, &dim.x, &dim.y);
        return (dim);
    }

}