/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** AnimationSystem.cpp
*/

#include "AnimationSystem.hpp"

namespace RT::GE::ECS::Systems {

    void AnimationSystem::init(std::shared_ptr<EntityManager> entityManager)
    {

    }

    void AnimationSystem::update(std::shared_ptr<EntityManager> entityManager)
    {
        static Lib::SDL2::Timer animTimer;
        ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<Entity, std::shared_ptr<Components::AComponent>, Entity::HashFunction> animations = componentManager.getComponents<Components::Animation>();

        animTimer.tick();
        float deltaTime = animTimer.getElapsedSeconds();
        if (deltaTime < 1) {
            for (auto &animation : animations) {
                std::shared_ptr<Components::ADrawable> cADrawable = componentManager.getComponent<Components::ADrawable>(animation.first);
                std::shared_ptr<Components::Animation> cAnimation = std::dynamic_pointer_cast<Components::Animation>(animation.second);

                if (cADrawable->getType() == Components::ADrawable::DrawableType::Spritesheet) {
                    std::shared_ptr<Components::SpriteSheet> cSpriteSheet = std::dynamic_pointer_cast<Components::SpriteSheet>(cADrawable);

                    cAnimation->updateIndex(deltaTime);
                    if (cAnimation->getDone()) {
                        entityManager->destroyEntity(animation.first);
                    } else {
                        cSpriteSheet->setIndex(cAnimation->getCurrentIndex());
                    }
                }
            }
        }
    }
}
