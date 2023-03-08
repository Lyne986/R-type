/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ClickUnselectSystem
*/

#include "HoverUnselectRoomSystem.hpp"

namespace RT::Client::Systems {

    void HoverUnselectRoomSystem::init(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {

    }

    void HoverUnselectRoomSystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        std::string name = "";
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> unselectRooms = componentManager.getComponents<Components::UnselectRoom>();
        
        for (auto &it : unselectRooms) {
            std::shared_ptr<Components::UnselectRoom> cButton = std::dynamic_pointer_cast<Components::UnselectRoom>(it.second);
            std::shared_ptr<RT::GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<RT::GE::ECS::Components::ADrawable>(it.first);

            if (cDrawable->getType() == RT::GE::ECS::Components::ADrawable::Spritesheet) {
                std::shared_ptr<RT::GE::ECS::Components::SpriteSheet> cSpriteSheet = std::dynamic_pointer_cast<RT::GE::ECS::Components::SpriteSheet>(cDrawable);
                GE::Utils::Vector2<int> pos = cDrawable->getPos();
                GE::Utils::Vector2<int> dim = cDrawable->getDim();
                name = cSpriteSheet->getName();

                if (name == "assets/images/card_1.png" || name ==  "assets/images/card_2.png") {
                    if (cButton->getHover(pos, dim) == true && cSpriteSheet->getIndex() != RT::GE::Utils::Vector2<int>{0, 2}) {
                        cSpriteSheet->setIndex(RT::GE::Utils::Vector2<int>{0, 1});
                    } else if (cButton->getHover(pos, dim) == false) {
                        cSpriteSheet->setIndex(RT::GE::Utils::Vector2<int>{0, 0});
                    }
                }
            }

        }
    }
}
