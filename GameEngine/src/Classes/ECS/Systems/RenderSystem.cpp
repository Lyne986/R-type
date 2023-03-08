/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** RenderSystem.cpp
*/

#include "RenderSystem.hpp"

namespace RT::GE::ECS::Systems {

    void RenderSystem::init(std::shared_ptr<EntityManager> entityManager)
    {

    }

    void RenderSystem::update(std::shared_ptr<EntityManager> entityManager)
    {
        ComponentManager &componentManager = entityManager->getComponentManager();
        std::map<unsigned int, std::vector<std::shared_ptr<Components::ADrawable>>> spriteLayers;
        std::unordered_map<Entity, std::shared_ptr<Components::AComponent>, Entity::HashFunction> drawables = componentManager.getComponents<Components::ADrawable>();

        for (auto &drawable : drawables) {
            std::shared_ptr<Components::ADrawable> cDrawable = std::dynamic_pointer_cast<Components::ADrawable>(drawable.second);
            if (!cDrawable->isVisible()) {
                continue;
            }

            std::shared_ptr<Components::Position> cPosition = componentManager.getComponent<Components::Position>(drawable.first);
            Utils::Vector2<float> pos = cPosition->get();
            Utils::Vector2<int> newPos = Utils::Vector2<int>(std::round(pos.x), std::round(pos.y));

            cDrawable->setPos(newPos);
            spriteLayers[cDrawable->getLayer()].push_back(cDrawable);
        }

        for (auto& spriteLayer : spriteLayers) {
            for (std::shared_ptr<Components::ADrawable> sprite : spriteLayer.second) {
                sprite->draw();
            }
        }
    }
}
