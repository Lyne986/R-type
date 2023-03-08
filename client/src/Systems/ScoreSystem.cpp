/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ScoreSystem.cpp
*/

#include "ScoreSystem.hpp"

namespace RT::Client::Systems {

    void ScoreSystem::init(std::shared_ptr<GE::ECS::EntityManager>)
    {

    }

    void ScoreSystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> scores = componentManager.getComponents<Components::Score>();

        for (auto &score : scores) {
            std::shared_ptr<Components::Score> cScore = std::dynamic_pointer_cast<Components::Score>(score.second);
            std::shared_ptr<GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<GE::ECS::Components::ADrawable>(score.first);

            if (cDrawable->getType() == RT::GE::ECS::Components::ADrawable::Text) {
                std::shared_ptr<RT::GE::ECS::Components::Text> cText = std::dynamic_pointer_cast<RT::GE::ECS::Components::Text>(cDrawable);

                cText->setText("Score: " + std::to_string(cScore->getScore()));
            }
        }
    }

}