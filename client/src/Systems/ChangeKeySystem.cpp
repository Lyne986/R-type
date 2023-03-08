/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ChangeKeySystem
*/

#include "ChangeKeySystem.hpp"

namespace RT::Client::Systems {

    void ChangeKeySystem::init(std::shared_ptr<GE::ECS::EntityManager>)
    {

    }

    void ChangeKeySystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> buttonScene = componentManager.getComponents<Components::ChangeKey>();
        for (auto &it : buttonScene) {
            std::shared_ptr<Components::ChangeKey> cChangeKey = std::dynamic_pointer_cast<Components::ChangeKey>(it.second);
            std::shared_ptr<RT::GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<RT::GE::ECS::Components::ADrawable>(it.first);

            if (cDrawable->getType() == RT::GE::ECS::Components::ADrawable::Text) {
                GE::Utils::Vector2<int> pos = cDrawable->getPos();
                GE::Utils::Vector2<int> dim = cDrawable->getDim();
                std::string key = cChangeKey->getClick(pos, dim);
                std::shared_ptr<RT::GE::ECS::Components::Text> cText = std::dynamic_pointer_cast<RT::GE::ECS::Components::Text>(cDrawable);
                if (key != "") {
                    // std::cout << "key" << std::endl;
                    cText->setText(key);
                }

            }

        }
    }

}
