#ifndef __RT_GAMEENGINE_ECS_COMPONENTS_SPRITESHEET_HPP__
    #define __RT_GAMEENGINE_ECS_COMPONENTS_SPRITESHEET_HPP__

    #include "ECSNamespace.hpp"
    #include "Lib/SDL2/Graphic/SpriteSheet.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Lib/SDL2/Graphic/Renderer.hpp"
    #include "ECS/Components/ADrawable.hpp"

class RT::GE::ECS::Components::SpriteSheet
 : public RT::GE::ECS::Components::ADrawable {

    protected:
    Lib::SDL2::Graphic::SpriteSheet spriteSheet;

    public:
    SpriteSheet(
        Lib::SDL2::Graphic::Renderer &renderer,
        Lib::SDL2::Graphic::SpriteManager &spriteManager,
        std::string path,
        unsigned int layer,
        Utils::Vector2<int> nbSprite,
        Utils::Vector2<int> pos,
        Utils::Vector2<int> dim
    );
    ~SpriteSheet() {};

    void draw();
    void setPos(Utils::Vector2<int> newPos);
    Utils::Vector2<int> getDim() const;
    Utils::Vector2<int> getPos() const;
    void setIndex(Utils::Vector2<int> index);
    Utils::Vector2<int> getIndex() const;
    Lib::SDL2::Graphic::SpriteSheet &getSpriteSheet();
    std::string getName();
};

#endif
