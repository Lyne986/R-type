/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** MovementSystem.cpp
*/

#include "MovementSystem.hpp"

namespace RT::GE::ECS::Systems {

    void MovementSystem::init(std::shared_ptr<EntityManager> entityManager)
    {

    }

    void MovementSystem::update(std::shared_ptr<EntityManager> entityManager)
    {
        static Lib::SDL2::Timer physicsTimer;
        ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<Entity, std::shared_ptr<Components::AComponent>, Entity::HashFunction> movables = componentManager.getComponents<Components::Movable>();

        physicsTimer.tick();
        for (auto &movable : movables) {
            std::shared_ptr<Components::Position> cPosition = componentManager.getComponent<Components::Position>(movable.first);
            std::shared_ptr<Components::Velocity> cVelocity = componentManager.getComponent<Components::Velocity>(movable.first);
            std::shared_ptr<Components::Movable> cMovable = std::dynamic_pointer_cast<Components::Movable>(movable.second);

            cMovable->move(cPosition->get(), cVelocity->get(), physicsTimer.getElapsedSeconds());
        }
    }
}
