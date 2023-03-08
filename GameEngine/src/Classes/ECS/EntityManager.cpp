/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** EntityManager.cpp
*/

#include "ECS/EntityManager.hpp"

namespace RT::GE::ECS {

    EntityManager::EntityManager(ComponentManager &componentManager, Lib::SDL2::Graphic::Renderer &renderer, Lib::SDL2::Graphic::SpriteManager &spriteManager, std::string objectsPath)
    : componentManager(componentManager), renderer(renderer), spriteManager(spriteManager) {
        this->objectsPath = objectsPath;
    }

    void EntityManager::init() {
        for (const auto& entry : std::filesystem::directory_iterator(this->objectsPath)) {
            std::string path{ entry.path().u8string() };
            this->entities.insert(this->createEntity(path));
        }
        Utils::Debug::Log::LogMessage(GE::Utils::Debug::Log::GameEngine, "Entities created: " + std::to_string(this->entities.size()));
        for (Entity entity : this->entities) {
            Utils::Debug::Log::LogMessage(GE::Utils::Debug::Log::GameEngine, entity);
        }
    }

    Entity EntityManager::createEntity(std::string name) {
        Utils::JSON json(name);
        nlohmann::json data = json.getData();
        Entity entity(data["name"]);

        if (data["pos"] != nullptr) {
            this->createPosition(entity, data);
        }
        if (data["velocity"] != nullptr) {
            this->createVelocity(entity, data);
        }
        if (data["speed"] != nullptr) {
            this->createMovable(entity, data);
        }
        if (data["text"] != nullptr) {
            this->createText(entity, data);
        }
        if (data["sprite"] != nullptr) {
            this->createSpriteSheet(entity, data);
        }
        if (data["parallax"] != nullptr) {
            this->createParallax(entity, data);
        }
        if (data["collider"] != nullptr) {
            this->createCollider(entity, data);
        }
        if (data["animations"] != nullptr)
        {
            this->createAnimations(entity, data);
        }
        for (auto function : this->parsingFunctions) {
            function(entity, data);
        }
        return (entity);
    }

    void EntityManager::registerFunction(std::function<void(Entity, nlohmann::json)> function) {
        this->parsingFunctions.push_back(function);
    }

    void EntityManager::createPosition(Entity entity, nlohmann::json data)
    {
        Components::Position position(
            Utils::Vector2<float>(
                data["pos"]["x"],
                data["pos"]["y"]
            )
        );
        this->componentManager.addComponent<Components::Position>(entity, position);
    }

    void EntityManager::createVelocity(Entity entity, nlohmann::json data)
    {
        Components::Velocity velocity(
            Utils::Vector2<float>(
                data["velocity"]["x"],
                data["velocity"]["y"]
            )
        );

        this->componentManager.addComponent<Components::Velocity>(entity, velocity);
    }

    void EntityManager::createMovable(Entity entity, nlohmann::json data)
    {
        Components::Movable Movable(
            Utils::Vector2<float>(
                data["speed"]["x"],
                data["speed"]["y"]
            )
        );

        this->componentManager.addComponent<Components::Movable>(entity, Movable);
    }

    void EntityManager::createText(Entity entity, nlohmann::json data)
    {
        std::string content = data["text"]["content"];
        Utils::Vector2<int> pos(
            data["pos"]["x"],
            data["pos"]["y"]
        );
        unsigned int size(data["text"]["size"]);
        unsigned int layer(data["text"]["layer"]);
        SDL_Color color;
        color.r = data["text"]["color"]["r"];
        color.g = data["text"]["color"]["g"];
        color.b = data["text"]["color"]["b"];
        color.a = data["text"]["color"]["a"];
        std::string font = data["text"]["font"];
        std::shared_ptr<Components::Text> text = std::make_shared<Components::Text>(
            this->renderer, content, pos, size, layer, color, font
        );
        this->componentManager.addComponent<Components::ADrawable>(entity, text);
    }

    void EntityManager::createSpriteSheet(Entity entity, nlohmann::json data)
    {
        std::string basePath = "assets/";
        std::string path = basePath + std::string(data["sprite"]["src"]);
        Utils::Vector2<int> nbSprite(
            data["sprite"]["nbSprite"]["x"],
            data["sprite"]["nbSprite"]["y"]
        );
        Utils::Vector2<int> pos(
            data["pos"]["x"],
            data["pos"]["y"]
        );
        Utils::Vector2<int> dim(
            data["sprite"]["dim"]["x"],
            data["sprite"]["dim"]["y"]
        );
        Utils::Vector2<int> index(
            data["sprite"]["index"]["x"],
            data["sprite"]["index"]["y"]
        );
        unsigned int layer(data["sprite"]["layer"]);
        std::shared_ptr<Components::SpriteSheet> spriteSheet = std::make_shared<Components::SpriteSheet>(
            this->renderer,
            this->spriteManager,
            path, layer, nbSprite, pos, dim
        );

        spriteSheet->setIndex(index);
        this->componentManager.addComponent<Components::ADrawable>(entity, spriteSheet);
    }

    void EntityManager::createParallax(Entity entity, nlohmann::json data)
    {
        std::string basePath = "assets/";
        std::string path = basePath + std::string(data["parallax"]["src"]);
        Utils::Vector2<int> pos(
            data["pos"]["x"],
            data["pos"]["y"]
        );
        Utils::Vector2<int> dim(
            data["parallax"]["dim"]["x"],
            data["parallax"]["dim"]["y"]
        );
        unsigned int layer(data["parallax"]["layer"]);
        std::shared_ptr<Components::SpriteSheet> parallax = std::make_shared<Components::Parallax>(
            this->renderer,
            this->spriteManager,
            path, layer, pos, dim
        );

        this->componentManager.addComponent<Components::ADrawable>(entity, parallax);
    }

    void EntityManager::createCollider(Entity entity, nlohmann::json data)
    {
        Utils::Vector2<int> pos(
            data["pos"]["x"],
            data["pos"]["y"]
        );
        Utils::Vector2<int> offset(
            data["collider"]["offset"]["x"],
            data["collider"]["offset"]["y"]
        );
        Utils::Vector2<int> dim(
            data["collider"]["dim"]["x"],
            data["collider"]["dim"]["y"]
        );
        bool isTrigger = data["collider"]["trigger"];
        unsigned int layer = data["collider"]["layer"];
        std::vector<unsigned int> collidingLayers;
        for (unsigned int collidingLayer : data["collider"]["collidingLayers"]) {
            collidingLayers.push_back(collidingLayer);
        }
        std::shared_ptr<Components::Collider> collider = std::make_shared<Components::Collider>(pos, offset, dim, isTrigger, layer, collidingLayers);

        this->componentManager.addComponent<Components::Collider>(entity, collider);
    }

    void EntityManager::createAnimations(Entity entity, nlohmann::json data)
    {
        std::shared_ptr<Components::Animation> animation = std::make_shared<Components::Animation>(data["animations"]);

        this->componentManager.addComponent<Components::Animation>(entity, animation);
    }

    void EntityManager::destroyEntity(Entity entity)
    {
        this->componentManager.removeEntityComponents(entity);
        this->entities.erase(entity);
        Utils::Debug::Log::LogMessage(GE::Utils::Debug::Log::GameEngine, "Deleted " + std::string(entity));
    }

    Entity EntityManager::getEntity(std::string name)
    {
        for (auto &entity: this->entities) {
            if (entity.getName() == name) {
                return entity;
            }
        }
        throw Utils::Error("Entity not found: " + name);
    }

    ComponentManager &EntityManager::getComponentManager()
    {
        return this->componentManager;
    }
}