/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Collider.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_COLLIDER_HPP__
    #define __RT_GE_ECS_COMPONENTS_COLLIDER_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"
    #include "Lib/SDL2/Graphic/Rect.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "ECS/Entity.hpp"
    #include <vector>
    #include <cmath>
    #include <algorithm>

class RT::GE::ECS::Components::Collider
 : public RT::GE::ECS::Components::AComponent {

    private:
        Lib::SDL2::Graphic::Rect rect;
        bool colliding = false;
        bool isTrigger = false;
        std::vector<Entity> collidingEntities;
        std::vector<Entity> ignoringEntities;
        Utils::Vector2<int> offset;
        unsigned int layer;
        std::vector<unsigned int> collidingLayers;

    public:
        Collider(Utils::Vector2<int> pos, Utils::Vector2<int> offset, Utils::Vector2<int> dim, bool isTrigger, unsigned int layer, std::vector<unsigned int> collidingLayers);
        ~Collider();

        bool isColliding(Entity entity, Collider collider);
        bool isColliding(Utils::Vector2<float> pos, Collider collider);
        void clearCollisions();
        void updateCollisions();
        void addCollidingEntity(Entity entity);
        void addIgnoringEntity(Entity entity);

        bool getIsColliding() const;
        void setIsColliding(bool value);
        std::vector<Entity> getCollidingEntities() const;
        std::vector<Entity> getIgnoringEntities() const;
        bool getIsTrigger() const;
        Lib::SDL2::Graphic::Rect getRect() const;
        void setRect(int x, int y, int width, int height);
        void setRectPosition(int x, int y);

};

#endif
