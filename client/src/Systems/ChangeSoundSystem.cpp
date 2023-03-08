/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ChangeSoundSystem
*/

#include "ChangeSoundSystem.hpp"

namespace RT::Client::Systems {

    void ChangeSoundSystem::init(std::shared_ptr<GE::ECS::EntityManager>)
    {

    }

    void ChangeSoundSystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> buttonScene = componentManager.getComponents<Components::ButtonSound>();
        for (auto &it : buttonScene) {
            std::shared_ptr<Components::ButtonSound> cButton = std::dynamic_pointer_cast<Components::ButtonSound>(it.second);
            std::shared_ptr<RT::GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<RT::GE::ECS::Components::ADrawable>(it.first);

            if (cDrawable->getType() == RT::GE::ECS::Components::ADrawable::Spritesheet) {
                GE::Utils::Vector2<int> pos = cDrawable->getPos();
                GE::Utils::Vector2<int> dim = cDrawable->getDim();
                cButton->getClick(pos, dim);
            }
        }
    }

}
