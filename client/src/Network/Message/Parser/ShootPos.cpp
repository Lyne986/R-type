#include "Network/Message/Parser/ShootPos.hpp"

namespace RT::Client::Network::Message::Parser {
    ShootPos::ShootPos(std::shared_ptr<GE::Scene::SceneManager> sceneManager): AParser(sceneManager)
    {
    }

    void ShootPos::parse(std::shared_ptr<RT::GE::Network::Client::Client>, message_s<CustomMsgTypes> msg)
    {
        GE::Network::Message::ShootPos shoot;
        msg >> shoot;
        GE::Utils::Vector2<float> pos(shoot.x, shoot.y);

        GE::ECS::ComponentManager &componentManager = this->entityManager->getComponentManager();
        GE::ECS::Entity bullet = this->entityManager->createEntity("assets/objects/prefabs/bullet.json");
        std::shared_ptr<Components::Damage> cDamage = std::make_shared<Components::Damage>(1, true);
        std::shared_ptr<GE::ECS::Components::Position> bulletPosition = componentManager.getComponent<GE::ECS::Components::Position>(bullet);
        std::shared_ptr<GE::ECS::Components::Collider> bulletCollider = componentManager.getComponent<GE::ECS::Components::Collider>(bullet);
        auto players = componentManager.getComponents<Components::OnlinePlayer>();

        for (auto &p : players) {
            std::shared_ptr<Components::OnlinePlayer> cOnlinePlayer = std::dynamic_pointer_cast<Components::OnlinePlayer>(p.second);
            if (cOnlinePlayer->getPid() == shoot.pid) {
                std::shared_ptr<GE::ECS::Components::Collider> playerCollider = componentManager.getComponent<GE::ECS::Components::Collider>(p.first);
                bulletCollider->addIgnoringEntity(p.first);
                playerCollider->addIgnoringEntity(bullet);
            }
        }
        bulletPosition->set(pos);
        componentManager.addComponent<Components::Damage>(bullet, cDamage);
    }
}