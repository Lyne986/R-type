#include "Network/Message/Parser/PlayerJoin.hpp"

namespace RT::Client::Network::Message::Parser {

    PlayerJoin::PlayerJoin(std::shared_ptr<GE::Scene::SceneManager> sceneManager) : AParser(sceneManager) {}

    void PlayerJoin::parse(std::shared_ptr<RT::GE::Network::Client::Client>, message_s<CustomMsgTypes> msg)
    {
        RT::GE::Network::Message::PlayerJoin joinMessage;
        msg >> joinMessage;
        int pid = joinMessage.pid;

        GE::ECS::ComponentManager &componentManager = this->entityManager->getComponentManager();
        auto onlinePlayers = componentManager.getComponents<Components::OnlinePlayer>();
        // // std::cout << "PlayerJoin::parse: " << pid << std::endl;
        // std::cout << "PlayerJoin::parse size : " << onlinePlayers.size() << std::endl;
        for (auto &onlinePlayer : onlinePlayers) {
            // // std::cout << "PlayerJoin::parse: loop " << onlinePlayer.first << std::endl;
            std::shared_ptr<Components::OnlinePlayer> onlinePlayerComponent = std::static_pointer_cast<Components::OnlinePlayer>(onlinePlayer.second);
            if (onlinePlayerComponent->getPid() == -1) {
                onlinePlayerComponent->connected(true);
                // // std::cout << "PlayerJoin::parse: SET CONNECTED " << onlinePlayerComponent->getPid() << std::endl;
                onlinePlayerComponent->setPid(pid);
                break;
            }
        }
    }

}