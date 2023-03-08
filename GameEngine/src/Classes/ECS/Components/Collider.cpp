/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Collider.cpp
*/

#include "ECS/Components/Collider.hpp"

namespace RT::GE::ECS::Components {

    Collider::Collider(Utils::Vector2<int> pos, Utils::Vector2<int> offset, Utils::Vector2<int> dim, bool isTrigger, unsigned int layer, std::vector<unsigned int> collidingLayers):
    rect(pos.x + offset.x, pos.y + offset.y, dim.x, dim.y),
    AComponent("collider")
    {
        this->offset = offset;
        this->isTrigger = isTrigger;
        this->layer = layer;
        this->collidingLayers = collidingLayers;
    }

    Collider::~Collider()
    {

    }

    bool Collider::isColliding(Entity entity, Collider collider)
    {
        std::vector<RT::GE::ECS::Entity>::iterator it = std::find(this->ignoringEntities.begin(), this->ignoringEntities.end(), entity);

        if (it != this->ignoringEntities.end()) {
            return false;
        }
        if (std::find(this->collidingLayers.begin(), this->collidingLayers.end(), collider.layer) != this->collidingLayers.end()) {
            return this->rect.isOverlapping(this->rect.getRect(), collider.rect.getRect());
        }
        return false;
    }

    bool Collider::isColliding(Utils::Vector2<float> nextPos, Collider collider)
    {
        if (std::find(this->collidingLayers.begin(), this->collidingLayers.end(), collider.layer) == this->collidingLayers.end()) {
            return false;
        }
        Utils::Vector2<int> roundedPos = Utils::Vector2<int>(std::round(nextPos.x), std::round(nextPos.y));
        Lib::SDL2::Graphic::Rect newRect(this->rect);

        newRect.setRectPosition(roundedPos.x, roundedPos.y);
        return this->rect.isOverlapping(newRect.getRect(), collider.rect.getRect());
    }

    bool Collider::getIsColliding() const
    {
        return this->colliding;
    }

    void Collider::setIsColliding(bool value)
    {
        this->colliding = value;
    }

    void Collider::clearCollisions()
    {
        this->colliding = false;
        this->collidingEntities.clear();
    }

    void Collider::updateCollisions()
    {
        for (Entity entity : this->ignoringEntities) {
            std::vector<RT::GE::ECS::Entity>::iterator it = std::find(this->collidingEntities.begin(), this->collidingEntities.end(), entity);
            if (it != this->collidingEntities.end()) {
                this->collidingEntities.erase(it);
            }
        }
    }

    void Collider::addCollidingEntity(Entity entity)
    {
        if (!this->colliding) {
            this->colliding = true;
        }
        this->collidingEntities.push_back(entity);
    }

    std::vector<Entity> Collider::getCollidingEntities() const
    {
        return this->collidingEntities;
    }

    void Collider::addIgnoringEntity(Entity entity)
    {
        if (std::find(this->ignoringEntities.begin(), this->ignoringEntities.end(), entity) == this->ignoringEntities.end()) {
            this->ignoringEntities.push_back(entity);
        }
    }

    std::vector<Entity> Collider::getIgnoringEntities() const
    {
        return this->ignoringEntities;
    }

    bool Collider::getIsTrigger() const
    {
        return this->isTrigger;
    }

    Lib::SDL2::Graphic::Rect Collider::getRect() const
    {
        return this->rect;
    }

    void Collider::setRect(int x, int y, int width, int height)
    {
        this->rect.setRect(x + this->offset.x, y + this->offset.y, width, height);
    }

    void Collider::setRectPosition(int x, int y)
    {
        this->rect.setRectPosition(x + this->offset.x, y + this->offset.y);
    }

}