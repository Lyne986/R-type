/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** EnemySystem.cpp
*/

#include "EnemySystem.hpp"

namespace RT::Client::Systems {

    void EnemySystem::init(std::shared_ptr<GE::ECS::EntityManager>)
    {

    }

    void EnemySystem::update(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        static GE::Lib::SDL2::Timer timer;
        timer.tick();
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        std::unordered_map<RT::GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, RT::GE::ECS::Entity::HashFunction> enemies = componentManager.getComponents<Components::Enemy>();
        float deltaTime = timer.getElapsedSeconds();

        if (deltaTime > 1) {
            return;
        }
        for (auto &enemy : enemies) {
            std::shared_ptr<GE::ECS::Components::Velocity> cVelocity = componentManager.getComponent<GE::ECS::Components::Velocity>(enemy.first);
            std::shared_ptr<GE::ECS::Components::Position> cPosition = componentManager.getComponent<GE::ECS::Components::Position>(enemy.first);
            std::shared_ptr<Components::Enemy> cEnemy = std::dynamic_pointer_cast<Components::Enemy>(enemy.second);

            if (cPosition->get().x < -60) {
                entityManager->destroyEntity(enemy.first);
            } else {
                cEnemy->updateState(deltaTime);
                cVelocity->set(cEnemy->getCurrentVelocity());
                if (cEnemy->getCanShoot() && cEnemy->updateShoot(deltaTime)) {
                    this->shootBullet(entityManager, enemy.first, cEnemy->getBulletPath());
                }
            }
        }
    }

    void EnemySystem::shootBullet(std::shared_ptr<GE::ECS::EntityManager> entityManager, GE::ECS::Entity enemy, std::string bulletPath)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        GE::ECS::Entity bullet = entityManager->createEntity(bulletPath);
        std::shared_ptr<GE::ECS::Components::Position> bulletPosition = componentManager.getComponent<GE::ECS::Components::Position>(bullet);
        std::shared_ptr<GE::ECS::Components::Collider> bulletCollider = componentManager.getComponent<GE::ECS::Components::Collider>(bullet);
        std::shared_ptr<GE::ECS::Components::Position> enemyPosition = componentManager.getComponent<GE::ECS::Components::Position>(enemy);
        std::shared_ptr<GE::ECS::Components::Collider> enemyCollider = componentManager.getComponent<GE::ECS::Components::Collider>(enemy);
        std::shared_ptr<GE::ECS::Components::Animation> enemyAnimation = componentManager.getComponent<GE::ECS::Components::Animation>(enemy);

        bulletCollider->addIgnoringEntity(enemy);
        enemyCollider->addIgnoringEntity(bullet);
        bulletPosition->set(bulletPosition->get() + enemyPosition->get());
        if (enemyAnimation != nullptr && enemyAnimation->hasAnim("shoot")) {
            enemyAnimation->setCurrentAnim("shoot");
        }
    }

}