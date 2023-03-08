/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ReleaseButtonSceneSystem
*/

#include "ReleaseButtonSceneSystem.hpp"

namespace RT::Client::Systems {

    void ReleaseButtonSceneSystem::init(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {

    }

    void ReleaseButtonSceneSystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        std::string name = "";
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> buttonScene = componentManager.getComponents<Components::ButtonScene>();
        for (auto &it : buttonScene) {
            std::shared_ptr<Components::ButtonScene> cButton = std::dynamic_pointer_cast<Components::ButtonScene>(it.second);
            std::shared_ptr<RT::GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<RT::GE::ECS::Components::ADrawable>(it.first);

            if (cDrawable->getType() == RT::GE::ECS::Components::ADrawable::Spritesheet) {
                GE::Utils::Vector2<int> pos = cDrawable->getPos();
                GE::Utils::Vector2<int> dim = cDrawable->getDim();
                std::shared_ptr<RT::GE::ECS::Components::SpriteSheet> cSpriteSheet = std::dynamic_pointer_cast<RT::GE::ECS::Components::SpriteSheet>(cDrawable);
                name = cSpriteSheet->getName();

                if (name == "assets/images/return.png" || name ==  "assets/images/settings_button.png" || name == "assets/images/quit_button.png" || name == "assets/images/play_button.png") {
                    if (cButton->getClickMenu(pos, dim) == true) {
                        cSpriteSheet->setIndex(RT::GE::Utils::Vector2<int>{0, 2});
                        continue;
                    }
                    if (cButton->getReleaseMenu(pos, dim) == true) {
                        cButton->onClick();
                        return;
                    }
                    continue;
                }

                cButton->getClick(pos, dim);
            }

        }
    }

}
