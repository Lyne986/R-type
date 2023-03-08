/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ComponentManager.cpp
*/

#include "ECS/ComponentManager.hpp"

namespace RT::GE::ECS {

    void ComponentManager::removeEntityComponents(Entity entity)
    {
        for (auto &typeComponents : this->components) {
            if (typeComponents.second.find(entity) != typeComponents.second.end()) {
                typeComponents.second.erase(entity);
            }
        }
    }
}