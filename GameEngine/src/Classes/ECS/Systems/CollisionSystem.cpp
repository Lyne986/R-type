/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** CollisionSystem.cpp
*/

#include "CollisionSystem.hpp"

namespace RT::GE::ECS::Systems {

    void CollisionSystem::init(std::shared_ptr<EntityManager> entityManager)
    {

    }

    void CollisionSystem::update(std::shared_ptr<EntityManager> entityManager)
    {
        ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<Entity, std::shared_ptr<Components::AComponent>, Entity::HashFunction> colliders = componentManager.getComponents<Components::Collider>();
        std::unordered_map<Entity, std::shared_ptr<Components::Collider>, Entity::HashFunction> cColliders;
        std::unordered_map<Entity, std::shared_ptr<Components::Movable>, Entity::HashFunction> cMovables;
        static GE::Lib::SDL2::Timer physicsTimer;
        physicsTimer.tick();

        for (auto &collider : colliders) {
            std::shared_ptr<Components::Position> cPosition = componentManager.getComponent<Components::Position>(collider.first);
            std::shared_ptr<Components::Collider> cCollider = std::dynamic_pointer_cast<Components::Collider>(collider.second);
            std::shared_ptr<GE::ECS::Components::Movable> cMovable = componentManager.getComponent<GE::ECS::Components::Movable>(collider.first);
            Utils::Vector2<float> &pos = cPosition->get();

            cCollider->clearCollisions();
            cCollider->setRectPosition(pos.x, pos.y);

            if (cMovable != nullptr) {
                // if (!cCollider->getIsTrigger()) {
                // }
                cColliders[collider.first] = cCollider;
                cMovables[collider.first] = cMovable;
            } else {
                cColliders[collider.first] = cCollider;
            }
        }

        for (auto &cMovable : cMovables) {
            std::shared_ptr<GE::ECS::Components::Collider> cCollider = componentManager.getComponent<GE::ECS::Components::Collider>(cMovable.first);
            std::shared_ptr<GE::ECS::Components::Velocity> cVelocity = componentManager.getComponent<GE::ECS::Components::Velocity>(cMovable.first);
            std::shared_ptr<GE::ECS::Components::Position> cPosition = componentManager.getComponent<GE::ECS::Components::Position>(cMovable.first);

            for (auto &other : cColliders) {
                if (cMovable.first.getId() != other.first.getId()) {
                    if (!cCollider->getIsTrigger() && !other.second->getIsTrigger()) {
                        GE::Utils::Vector2<float> predictedPosition = cMovable.second->getPredictedPosition(cPosition->get(), cVelocity->get(), physicsTimer.getElapsedSeconds());

                        if (cCollider->isColliding(predictedPosition, *other.second)) {
                            cVelocity->set(Utils::Vector2<float>(0, 0));
                        }

                    } else {
                        if (cCollider->isColliding(other.first, *other.second)) {
                            cCollider->addCollidingEntity(other.first);
                            other.second->addCollidingEntity(cMovable.first);
                        }
                    }
                }
            }
        }

    }

}
