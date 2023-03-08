/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Entity.cpp
*/

#include "ECS/Entity.hpp"

namespace RT::GE::ECS {

    std::size_t Entity::lastId = 0;

    Entity::Entity(std::string name) {
        this->id = ++Entity::lastId;
        this->name = name;
    }

    bool Entity::operator==(const Entity& otherEntity) const {
        return (this->id == otherEntity.id);
    }

    Entity::operator std::string() const
    {
        return "Entity " + std::to_string(this->id) + " " + this->name;
    }

    std::string Entity::getName() const {
        return (this->name);
    }

    std::size_t Entity::getId() const {
        return (this->id);
    }

}