/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Parallax.cpp
*/

#include "ECS/Components/Parallax.hpp"

namespace RT::GE::ECS::Components {

    Parallax::Parallax(
        Lib::SDL2::Graphic::Renderer &renderer,
        Lib::SDL2::Graphic::SpriteManager &spriteManager,
        std::string path,
        unsigned int layer,
        Utils::Vector2<int> pos,
        Utils::Vector2<int> dim
    ) : SpriteSheet(renderer, spriteManager, path, layer, Utils::Vector2<int>(1, 1), pos, dim) {

    }
}