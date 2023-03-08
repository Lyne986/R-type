/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** SystemManager.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_SYSTEMMANAGER_HPP__
    #define __RT_GAMEENGINE_ECS_SYSTEMMANAGER_HPP__

    #include "Systems/ASystem.hpp"
    #include "EntityManager.hpp"
    #include "Utils/Error.hpp"
    #include <memory>
    #include <unordered_map>
    #include <algorithm>
    #include <typeindex>
    #include <vector>

class RT::GE::ECS::SystemManager {
    private:
        std::vector<std::shared_ptr<Systems::ASystem>> logicSystems;
        std::vector<std::shared_ptr<Systems::ASystem>> renderSystems;
        std::unordered_map<std::type_index, size_t> knownSystems;

    public:
        template <typename SystemType>
        void addRenderSystem() {
            std::type_index systemType = std::type_index(typeid(SystemType));

            if (this->knownSystems.find(systemType) != this->knownSystems.end()) {
                throw Utils::Error("System already exists");
            } else {
                std::shared_ptr system = std::make_shared<SystemType>();
                knownSystems[systemType] = this->renderSystems.size();
                this->renderSystems.push_back(system);
            }
        }

        template <typename SystemType>
        void addLogicSystem() {
            std::type_index systemType = std::type_index(typeid(SystemType));

            if (this->knownSystems.find(systemType) != this->knownSystems.end()) {
                throw Utils::Error("System already exists");
            } else {
                std::shared_ptr system = std::make_shared<SystemType>();
                knownSystems[systemType] = this->logicSystems.size();
                this->logicSystems.push_back(system);
            }
        }

        template <typename SystemType>
        void removeLogicSystem() {
            std::type_index systemType = std::type_index(typeid(SystemType));

            if (this->knownSystems.find(systemType) != this->knownSystems.end()) {
                this->logicSystems.erase(this->logicSystems.begin() + this->knownSystems[systemType]);
            } else {
                throw Utils::Error("System doesn't exist");
            }
        }

        template <typename SystemType>
        void removeRenderSystem() {
            std::type_index systemType = std::type_index(typeid(SystemType));

            if (this->knownSystems.find(systemType) != this->knownSystems.end()) {
                this->renderSystems.erase(this->renderSystems.begin() + this->knownSystems[systemType]);
            } else {
                throw Utils::Error("System doesn't exist");
            }
        }

        void init(std::shared_ptr<EntityManager> entityManager);
        void updateLogic(std::shared_ptr<EntityManager> entityManager);
        void updateRender(std::shared_ptr<EntityManager> entityManager);
};

#endif