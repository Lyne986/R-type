#include "Systems/MainPlayer.hpp"

namespace RT::Client::Systems {

    MainPlayer::MainPlayer()
    {
    }

    MainPlayer::~MainPlayer()
    {
        GE::Network::Message::PlayerDisconnect playerDisconnect(this->pid, this->_IdInstance->getId());
        message_s<CustomMsgTypes> msg("PlayerDisconnect");
        msg.header.id = CustomMsgTypes::messageAll;
        msg << playerDisconnect;
        this->client->send(msg);
    }

    void MainPlayer::init(std::shared_ptr<GE::ECS::EntityManager>) {
    }

    void MainPlayer::update(std::shared_ptr<GE::ECS::EntityManager> entityManager) {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        auto &mainPlayer = componentManager.getComponents<Components::MainPlayer>();
        for (auto &player : mainPlayer) {
            std::shared_ptr<Components::MainPlayer> mainPlayer = std::dynamic_pointer_cast<Components::MainPlayer>(player.second);
            if (!mainPlayer->isConnected()) {
                this->updateUnConnected();
            } else {
                this->pid = mainPlayer->getPid();
                this->updateConnected(player.first, componentManager);
            }
        }
    }

    void MainPlayer::updateUnConnected() {
        GE::Network::Message::JoinMessage joinMessage(this->_IdInstance->getId(), this->_IdInstance->getId());
        message_s<CustomMsgTypes> msg("Join");
        msg.header.id = CustomMsgTypes::messageAll;
        msg << joinMessage;
        this->client->send(msg);
    }

    void MainPlayer::updateConnected(GE::ECS::Entity entity, GE::ECS::ComponentManager &componentManager) {
        std::shared_ptr<Components::MainPlayer> mainPlayer = componentManager.getComponent<Components::MainPlayer>(entity);
        std::shared_ptr<GE::ECS::Components::Position> positionComponent = componentManager.getComponent<GE::ECS::Components::Position>(entity);
        GE::Utils::Vector2<float> &position = positionComponent->get();
        GE::Network::Message::PlayerPosition playerPosition(mainPlayer->getPid(), position.x, position.y, this->_IdInstance->getId());
        message_s<CustomMsgTypes> msg("PlayerPosition");
        msg.header.id = CustomMsgTypes::messageAll;
        msg << playerPosition;
        // std::cout << "Send PlayerPosition " << position.x << " " << position.y << std::endl;
        this->client->sendUDP(msg);
    }

}
