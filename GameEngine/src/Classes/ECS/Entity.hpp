/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Entity.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_ENTITY_HPP__
    #define __RT_GAMEENGINE_ECS_ENTITY_HPP__

    #include "ECSNamespace.hpp"
    #include <string>
    #include <sstream>

class RT::GE::ECS::Entity {

    private:
    static std::size_t lastId;
    std::size_t id;
    std::string name;

    public:
    Entity(std::string name="Unknown");
    std::string getName() const;
    std::size_t getId() const;

    bool operator==(const Entity& otherEntity) const;
    operator std::string() const;

    struct HashFunction {
        std::size_t operator()(const Entity& entity) const {
            return (std::hash<std::size_t>()(entity.id));
        };
    };
};

inline std::ostream &operator<<(std::ostream &os, const RT::GE::ECS::Entity &entity) {
    os << "Entity " << entity.getId() << " " << entity.getName();
    return (os);
}


#endif