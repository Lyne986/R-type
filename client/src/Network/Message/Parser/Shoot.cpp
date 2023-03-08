#include "Shoot.hpp"

namespace RT::Client::Network::Message::Parser {
    Shoot::Shoot(std::shared_ptr<GE::Scene::SceneManager> sceneManager)
    : AParser(sceneManager) {}

    void Shoot::parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg)
    {
        RT::GE::Network::Message::Shoot_s shoot;
        msg >> shoot;
        this->launchAnimation(shoot);
    }

    void Shoot::launchAnimation(RT::GE::Network::Message::Shoot_s shoot)
    {
        GE::ECS::ComponentManager &componentManager = this->entityManager->getComponentManager();
        auto players = componentManager.getComponents<RT::Client::Components::OnlinePlayer>();
        GE::ECS::Entity playerEntity;

        for (auto player : players) {
            std::shared_ptr<RT::Client::Components::OnlinePlayer> onlinePlayer = std::static_pointer_cast<RT::Client::Components::OnlinePlayer>(player.second);
            if (onlinePlayer->getPid() == shoot.pid) {
                playerEntity = player.first;
                break;
            }
        }
        std::shared_ptr<GE::ECS::Components::Animation> playerAnimation = componentManager.getComponent<GE::ECS::Components::Animation>(playerEntity);
        GE::ECS::AudioManager::getInstance()->getSound("playerShot")->play();
        if (playerAnimation != nullptr && playerAnimation->hasAnim("shoot")) {
            playerAnimation->setCurrentAnim("shoot");
        }
    }
}
