#include "ECS/Components/SpriteSheet.hpp"

namespace RT::GE::ECS::Components {

    SpriteSheet::SpriteSheet(
        Lib::SDL2::Graphic::Renderer &renderer,
        Lib::SDL2::Graphic::SpriteManager &spriteManager,
        std::string path,
        unsigned int layer,
        Utils::Vector2<int> nbSprite,
        Utils::Vector2<int> pos,
        Utils::Vector2<int> dim
    ) : spriteSheet(renderer, spriteManager, path, nbSprite, pos, dim),
    ADrawable(ADrawable::Spritesheet, layer) {

    }

    void SpriteSheet::draw() {
        this->spriteSheet.draw();
    }

    void SpriteSheet::setPos(Utils::Vector2<int> newPos)
    {
        this->spriteSheet.setPos(newPos);
    }

    Utils::Vector2<int> SpriteSheet::getDim() const
    {
        return this->spriteSheet.getDim();
    }

    Utils::Vector2<int> SpriteSheet::getPos() const
    {
        return this->spriteSheet.getPos();
    }

    void SpriteSheet::setIndex(Utils::Vector2<int> index) {
        this->spriteSheet.setIndex(index);
    }

    Utils::Vector2<int> SpriteSheet::getIndex() const {
        return this->spriteSheet.getIndex();
    }

    Lib::SDL2::Graphic::SpriteSheet &SpriteSheet::getSpriteSheet() {
        return (this->spriteSheet);
    }

    std::string SpriteSheet::getName() {
        return (this->spriteSheet.getName());
    }

}
