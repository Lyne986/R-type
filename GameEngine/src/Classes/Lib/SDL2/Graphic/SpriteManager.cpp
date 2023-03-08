#include "SpriteManager.hpp"

namespace RT::GE::Lib::SDL2::Graphic {

    SpriteManager::SpriteManager() {
        this->sprites = {};
    }

    std::shared_ptr<Surface> SpriteManager::getSprite(std::string path) {
        if (this->sprites.find(path) == this->sprites.end()) {
            this->sprites[path] = std::make_shared<Surface>(path);
        }
        return (this->sprites[path]);
    }

}