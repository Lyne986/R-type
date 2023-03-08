/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** HealthSystem.cpp
*/

#include "HealthSystem.hpp"

namespace RT::Client::Systems
{

    void HealthSystem::init(std::shared_ptr<GE::ECS::EntityManager>)
    {
    }

    void HealthSystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> damages = componentManager.getComponents<Components::Damage>();

        for (auto &damage : damages)
        {
            std::shared_ptr<GE::ECS::Components::Collider> cCollider = componentManager.getComponent<GE::ECS::Components::Collider>(damage.first);

            if (cCollider) {
                std::shared_ptr<Components::Damage> cDamage = std::dynamic_pointer_cast<Components::Damage>(damage.second);
                std::vector<GE::ECS::Entity> collidingEntities = cCollider->getCollidingEntities();

                for (GE::ECS::Entity &collidingEntity : collidingEntities) {
                    std::shared_ptr<Components::Health> cHealth = componentManager.getComponent<Components::Health>(collidingEntity);

                    if (cHealth != nullptr) {
                        GE::ECS::AudioManager::getInstance()->getSound("objectDeath")->play();
                        cHealth->damage(cDamage->getDamage());
                        if (cHealth->getHealth() == 0) {
                            std::shared_ptr<GE::ECS::Components::Position> cPosition = componentManager.getComponent<GE::ECS::Components::Position>(collidingEntity);
                            GE::ECS::Entity explosion = entityManager->createEntity("assets/objects/prefabs/explosion.json");
                            componentManager.getComponent<GE::ECS::Components::Position>(explosion)->set(cPosition->get());
                            this->destroyEntity(entityManager, collidingEntity);
                        }
                    }
                }

                if (collidingEntities.size() != 0 && cDamage->getDestroyOnCollision()) {
                    std::shared_ptr<GE::ECS::Components::Position> cPosition = componentManager.getComponent<GE::ECS::Components::Position>(damage.first);
                    GE::ECS::Entity explosion = entityManager->createEntity("assets/objects/prefabs/bulletExplosion.json");
                    componentManager.getComponent<GE::ECS::Components::Position>(explosion)->set(cPosition->get());
                    this->destroyEntity(entityManager, damage.first);
                }
            }
        }
        this->updateUI(componentManager);
    }

    void HealthSystem::destroyEntity(std::shared_ptr<GE::ECS::EntityManager> entityManager, GE::ECS::Entity entity)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::shared_ptr<Components::Enemy> cEnemy = componentManager.getComponent<Components::Enemy>(entity);

        if (cEnemy != nullptr) {
            std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> scores = componentManager.getComponents<Components::Score>();
            std::shared_ptr<Components::Score> cScore = std::dynamic_pointer_cast<Components::Score>(scores.begin()->second);

            cScore->setScore(cScore->getScore() + cEnemy->getScoreValue());
        }
        entityManager->destroyEntity(entity);
    }

    void HealthSystem::updateUI(GE::ECS::ComponentManager &componentManager)
    {
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> players = componentManager.getComponents<Components::MainPlayer>();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> healthUIs = componentManager.getComponents<Components::HealthUI>();

        std::shared_ptr<Components::HealthUI> cHealthUI = std::dynamic_pointer_cast<Components::HealthUI>(healthUIs.begin()->second);
        std::shared_ptr<GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<GE::ECS::Components::ADrawable>(healthUIs.begin()->first);
        std::shared_ptr<GE::ECS::Components::Text> cText = std::dynamic_pointer_cast<GE::ECS::Components::Text>(cDrawable);

        if (players.size() == 0) {
            cHealthUI->setHealth(0);
        } else {
            std::shared_ptr<Components::Health> cHealth = componentManager.getComponent<Components::Health>(players.begin()->first);

            cHealthUI->setHealth(cHealth->getHealth());
        }
        cText->setText("Lives: " + std::to_string(cHealthUI->getHealth()));
    }

}