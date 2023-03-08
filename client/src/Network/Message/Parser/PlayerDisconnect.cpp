#include "Network/Message/Parser/PlayerDisconnect.hpp"

namespace RT::Client::Network::Message::Parser {

    PlayerDisconnect::PlayerDisconnect(std::shared_ptr<GE::Scene::SceneManager> sceneManager) : AParser(sceneManager) {}

    void PlayerDisconnect::parse(std::shared_ptr<RT::GE::Network::Client::Client>, message_s<CustomMsgTypes> msg) {
        GE::Network::Message::PlayerDisconnect playerDisconnect;
        msg >> playerDisconnect;
        int pid = playerDisconnect.pid;
        GE::ECS::ComponentManager &componentManager = this->entityManager->getComponentManager();
        std::unordered_map<GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, GE::ECS::Entity::HashFunction> &playerComponent = componentManager.getComponents<Components::OnlinePlayer>();
        for (auto &it : playerComponent) {
            std::shared_ptr<Components::OnlinePlayer> onlinePlayer = std::static_pointer_cast<Components::OnlinePlayer>(it.second);
            if (onlinePlayer->getPid() == pid) {
                onlinePlayer->connected(false);
                onlinePlayer->setPid(-1);
                break;
            }
        }
    }
}