/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** SpriteSheet.cpp
*/

#include "Lib/SDL2/Graphic/SpriteSheet.hpp"

namespace RT::GE::Lib::SDL2::Graphic {

    SpriteSheet::SpriteSheet(
        Renderer &renderer, SpriteManager &spriteManager,
        std::string path, Utils::Vector2<int> nbSprite, Utils::Vector2<int> pos, Utils::Vector2<int> dim)
    : renderer(renderer), src(0, 0, 0, 0), drawRect(pos.x, pos.y, dim.x, dim.y) {
        this->texture = std::make_shared<Texture>(renderer, spriteManager, path);
        this->nbSprite = nbSprite;
        this->pos = pos;
        this->srcDim = this->texture->getDim() / nbSprite;
        this->dim = dim;
        this->srcPos = this->currIndex * this->srcDim;
        this->src.setRect(this->srcPos.x, this->srcPos.y, this->srcDim.x, this->srcDim.y);
        this->name = path;
    }

    void SpriteSheet::draw() {
        this->drawRect.setRect(this->pos.x, this->pos.y, this->dim.x, this->dim.y);
        if (SDL_RenderCopy(this->renderer.getRenderer(), this->texture->getTexture(), &this->src.getRect(), &this->drawRect.getRect())) {
            throw Utils::Error("SDL_RenderCopy Error: " + std::string(SDL_GetError()));
        }
    }

    void SpriteSheet::setIndex(Utils::Vector2<int> index) {
        this->currIndex = index;
        this->srcPos = this->currIndex * this->srcDim;
        this->src = {this->srcPos.x, this->srcPos.y, this->srcDim.x, this->srcDim.y};
    }

    Utils::Vector2<int> SpriteSheet::getIndex() const {
        return this->currIndex;
    }

    void SpriteSheet::setPos(Utils::Vector2<int> pos) {
        this->pos = pos;
    }

    Utils::Vector2<int> SpriteSheet::getPos() const
    {
        return (this->pos);
    }

    Utils::Vector2<int> SpriteSheet::getDim() const
    {
        return this->dim;
    }

    std::string SpriteSheet::getName() const
    {
        return this->name;
    }
}
