/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Image.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_IMAGE_HPP__
    #define __RT_GE_ECS_COMPONENTS_IMAGE_HPP__

    #include "ECSNamespace.hpp"
    #include "Utils/Vector2.hpp"
    #include "ECS/Components/SpriteSheet.hpp"
    #include "Lib/SDL2/Graphic/SpriteSheet.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "Lib/SDL2/Graphic/Renderer.hpp"

class RT::GE::ECS::Components::Parallax
 : public RT::GE::ECS::Components::SpriteSheet {

    public:
        Parallax(
            Lib::SDL2::Graphic::Renderer &renderer,
            Lib::SDL2::Graphic::SpriteManager &spriteManager,
            std::string path,
            unsigned int layer,
            Utils::Vector2<int> pos,
            Utils::Vector2<int> dim
        );
        ~Parallax() {};
};

#endif