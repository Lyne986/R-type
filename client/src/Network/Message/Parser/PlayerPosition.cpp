#include "Network/Message/Parser/PlayerPosition.hpp"

namespace RT::Client::Network::Message::Parser {

    PlayerPosition::PlayerPosition(std::shared_ptr<GE::Scene::SceneManager> sceneManager): AParser(sceneManager) {
    }

    void PlayerPosition::parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg) {
        // std::cout << "RECEIVED PLAYER POSITION" << std::endl;
        GE::Network::Message::PlayerPosition playerPosition;
        msg >> playerPosition;
        GE::ECS::ComponentManager &componentManager = this->entityManager->getComponentManager();
        std::unordered_map<GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, GE::ECS::Entity::HashFunction> &components = componentManager.getComponents<Components::OnlinePlayer>();
        for (auto &component : components) {
            std::shared_ptr<Components::OnlinePlayer> onlinePlayer = std::dynamic_pointer_cast<Components::OnlinePlayer>(component.second);
            if (onlinePlayer->getPid() == playerPosition.pid) {
                std::shared_ptr<GE::ECS::Components::Position> position = componentManager.getComponent<GE::ECS::Components::Position>(component.first);
                position->set(GE::Utils::Vector2<float>(playerPosition.x, playerPosition.y));
                break;
            }
        }
    }

}