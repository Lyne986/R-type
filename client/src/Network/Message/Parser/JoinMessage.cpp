#include "JoinMessage.hpp"

namespace RT::Client::Network::Message::Parser {

    JoinMessage::JoinMessage(std::shared_ptr<GE::Scene::SceneManager> sceneManager) : AParser(sceneManager) {
        // std::cout << "JoinMessage created" << std::endl;
    }

    void JoinMessage::parse(std::shared_ptr<RT::GE::Network::Client::Client>, message_s<CustomMsgTypes> msg) {
        GE::Network::Message::JoinMessage joinMessage;
        msg >> joinMessage;
        int pid = joinMessage.pid;
        std::shared_ptr<GE::ECS::EntityManager> entityManager = this->entityManager;
        GE::ECS::ComponentManager &componentManager = this->entityManager->getComponentManager();
        std::unordered_map<GE::ECS::Entity, std::shared_ptr<GE::ECS::Components::AComponent>, GE::ECS::Entity::HashFunction> mainPlayerComponents = componentManager.getComponents<Components::MainPlayer>();
        // std::cout << "JoinMessage::parse: " << pid << std::endl;
        for (auto &mainPlayerComponent : mainPlayerComponents) {
            std::shared_ptr<Components::MainPlayer> mainPlayer = std::dynamic_pointer_cast<Components::MainPlayer>(mainPlayerComponent.second);
            mainPlayer->isConnected(true);
            mainPlayer->setPid(pid);
        }
    }

}