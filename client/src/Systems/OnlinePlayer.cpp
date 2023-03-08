#include "Systems/OnlinePlayer.hpp"

namespace RT::Client::Systems {
    
    void OnlinePlayer::init(std::shared_ptr<GE::ECS::EntityManager>) {
    }

    void OnlinePlayer::update(std::shared_ptr<GE::ECS::EntityManager> entityManager) {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        auto onlineComponents = componentManager.getComponents<RT::Client::Components::OnlinePlayer>();
        // // std::cout << "size " << onlineComponents.size() << std::endl;
        for (auto &onlineComponent : onlineComponents) {
            std::shared_ptr<Components::OnlinePlayer> onlinePlayer = std::dynamic_pointer_cast<Components::OnlinePlayer>(onlineComponent.second);
            std::shared_ptr<GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<GE::ECS::Components::ADrawable>(onlineComponent.first);
            // // std::cout << "onlinePlayer " << onlinePlayer->getPid() << " " << onlinePlayer->connected() << std::endl;
            cDrawable->setVisible(onlinePlayer->connected());
        }
        this->updateConnection();
    }

    void OnlinePlayer::updateConnected() {
    }

    void OnlinePlayer::updateUnconnected() {
    }

    void OnlinePlayer::updateConnection() {
    }

    
}
