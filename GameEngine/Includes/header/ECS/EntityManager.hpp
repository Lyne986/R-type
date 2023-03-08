/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** EntityManager.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_ENTITYMANAGER_HPP__
    #define __RT_GAMEENGINE_ECS_ENTITYMANAGER_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/Entity.hpp"
    #include "ECS/ComponentManager.hpp"
    #include "ECS/Components/Position.hpp"
    #include "ECS/Components/Velocity.hpp"
    #include "ECS/Components/Text.hpp"
    #include "ECS/Components/SpriteSheet.hpp"
    #include "ECS/Components/Parallax.hpp"
    #include "ECS/Components/Movable.hpp"
    #include "ECS/Components/Collider.hpp"
    #include "ECS/Components/Animation.hpp"

    #include "Utils/JSON.hpp"
    #include "Utils/Vector2.hpp"
    #include "Utils/Error.hpp"
    #include "Utils/Debug/Log.hpp"

    #include <nlohmann/json.hpp>
    #include <unordered_set>
    #include <string>
    #include <filesystem>
    #include <cstdlib>
    #include <memory>

class RT::GE::ECS::EntityManager {

    private:
    std::unordered_set<Entity, Entity::HashFunction> entities;
    ComponentManager &componentManager;
    Lib::SDL2::Graphic::Renderer &renderer;
    Lib::SDL2::Graphic::SpriteManager &spriteManager;
    std::vector<std::function<void(Entity, nlohmann::json)>> parsingFunctions = {};
    std::string objectsPath;

    void createPosition(Entity entity, nlohmann::json data);
    void createVelocity(Entity entity, nlohmann::json data);
    void createMovable(Entity entity, nlohmann::json data);
    void createText(Entity entity, nlohmann::json data);
    void createSpriteSheet(Entity entity, nlohmann::json data);
    void createParallax(Entity entity, nlohmann::json data);
    void createCollider(Entity entity, nlohmann::json data);
    void createAnimations(Entity entity, nlohmann::json data);

    public:
    EntityManager(ComponentManager &componentManager, Lib::SDL2::Graphic::Renderer &renderer, Lib::SDL2::Graphic::SpriteManager &spriteManager, std::string objectsPath);
    void init();
    void registerFunction(std::function<void(Entity, nlohmann::json)> function);

    Entity createEntity(std::string name);
    void destroyEntity(Entity entity);

    Entity getEntity(std::string name);
    ComponentManager &getComponentManager();
};

#endif