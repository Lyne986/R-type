/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** ComponentManager.hpp
*/

#ifndef __RT_GE_ECS_COMPONENT_MANAGER_HPP__
    #define __RT_GE_ECS_COMPONENT_MANAGER_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/Entity.hpp"
    #include "ECS/Components/AComponent.hpp"

    #include <unordered_map>
    #include <memory>
    #include <typeindex>

class RT::GE::ECS::ComponentManager {
    private:
    std::unordered_map<std::type_index, std::unordered_map<Entity, std::shared_ptr<Components::AComponent>, Entity::HashFunction>> components;

    public:
    template<typename T>
    void registerComponent() {
        this->components[std::type_index(typeid(T))] = std::unordered_map<Entity, std::shared_ptr<Components::AComponent>, Entity::HashFunction>();
    };

    template<typename T>
    void addComponent(Entity entity, T &component) {
        if (components.find(std::type_index(typeid(T))) == components.end()) {
            this->registerComponent<T>();
        }
        components[std::type_index(typeid(T))].insert(std::make_pair(entity, std::make_shared<T>(component)));
    }

    template<typename T>
    void addComponent(Entity entity, std::shared_ptr<T> component) {
        if (components.find(std::type_index(typeid(T))) == components.end()) {
            this->registerComponent<T>();
        }
        components[std::type_index(typeid(T))].insert(std::make_pair(entity, component));
    }

    template <typename T>
    std::unordered_map<Entity, std::shared_ptr<Components::AComponent>, Entity::HashFunction> &getComponents() {
        return (this->components[std::type_index(typeid(T))]);
    }

    template <typename T>
    std::shared_ptr<T> getComponent(Entity entity) {
        if (this->components[std::type_index(typeid(T))].find(entity) == this->components[std::type_index(typeid(T))].end()) {
            return nullptr;
        }
        return (std::static_pointer_cast<T>(this->components[std::type_index(typeid(T))][entity]));
    }

    void removeEntityComponents(Entity entity);
};

#endif