/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ClickButtonSceneSystem
*/

#include "ClickButtonSceneSystem.hpp"

namespace RT::Client::Systems {

    void ClickButtonSceneSystem::init(std::shared_ptr<GE::ECS::EntityManager>)
    {

    }

    void ClickButtonSceneSystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> buttonScene = componentManager.getComponents<Components::ButtonScene>();
        for (auto &it : buttonScene) {
            std::shared_ptr<Components::ButtonScene> cButton = std::dynamic_pointer_cast<Components::ButtonScene>(it.second);
            std::shared_ptr<RT::GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<RT::GE::ECS::Components::ADrawable>(it.first);

            if (cDrawable->getType() == RT::GE::ECS::Components::ADrawable::Spritesheet) {
                GE::Utils::Vector2<int> pos = cDrawable->getPos();
                GE::Utils::Vector2<int> dim = cDrawable->getDim();
                cButton->getClick(pos, dim);
            }
        }
    }

}
