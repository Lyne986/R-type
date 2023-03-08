/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** SystemManager.cpp
*/

#include "SystemManager.hpp"

namespace RT::GE::ECS {

    void SystemManager::init(std::shared_ptr<EntityManager> entityManager)
    {
        for (int i = 0; i < this->logicSystems.size(); i++) {
            std::shared_ptr<Systems::ASystem> system = this->logicSystems[i];
            system->init(entityManager);
        }
        for (int i = 0; i < this->renderSystems.size(); i++) {
            std::shared_ptr<Systems::ASystem> system = this->renderSystems[i];
            system->init(entityManager);
        }
    }

    void SystemManager::updateLogic(std::shared_ptr<EntityManager> entityManager)
    {
        for (int i = 0; i < this->logicSystems.size(); i++) {
            std::shared_ptr<Systems::ASystem> system = this->logicSystems[i];
            system->update(entityManager);
        }
    }

    void SystemManager::updateRender(std::shared_ptr<EntityManager> entityManager)
    {
        for (int i = 0; i < this->renderSystems.size(); i++) {
            std::shared_ptr<Systems::ASystem> system = this->renderSystems[i];
            system->update(entityManager);
        }
    }

}