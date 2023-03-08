/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ParallaxSystem.cpp
*/

#include "ParallaxSystem.hpp"

namespace RT::GE::ECS::Systems {

    void ParallaxSystem::init(std::shared_ptr<EntityManager> entityManager)
    {

    }

    void ParallaxSystem::update(std::shared_ptr<EntityManager> entityManager)
    {
        ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<Entity, std::shared_ptr<Components::AComponent>, Entity::HashFunction> drawables = componentManager.getComponents<Components::ADrawable>();

        for (auto &drawable : drawables) {
            std::shared_ptr<Components::Parallax> parallax = std::dynamic_pointer_cast<Components::Parallax>(drawable.second);
            if (parallax != nullptr) {
                std::shared_ptr<Components::Position> cPosition = componentManager.getComponent<Components::Position>(drawable.first);
                std::shared_ptr<Components::Velocity> cVelocity = componentManager.getComponent<Components::Velocity>(drawable.first);
                Utils::Vector2<float> &vel = cVelocity->get();
                Utils::Vector2<float> &pos = cPosition->get();
                Utils::Vector2<int> dim = parallax->getDim();

                if (vel.x < 0 && pos.x < -dim.x) {
                    pos.x = dim.x;
                } else if (vel.x > 0 && pos.x > dim.x) {
                    pos.x = -dim.x;
                }

                if (vel.y < 0 && pos.y < -dim.y) {
                    pos.y = dim.y;
                } else if (vel.y > 0 && pos.y > dim.y) {
                    pos.y = -dim.y;
                }

            }
        }
    }
}
