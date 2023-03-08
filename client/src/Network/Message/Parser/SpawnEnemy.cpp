#include "Network/Message/Parser/SpawnEnemy.hpp"

namespace RT::Client::Network::Message::Parser {

    SpawnEnemy::SpawnEnemy(std::shared_ptr<GE::Scene::SceneManager> sceneManager)
    : AParser(sceneManager)
    {
    }

    void SpawnEnemy::parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg)
    {
        GE::Network::Message::SpawnEnemy spawnEnemy;
        msg >> spawnEnemy;
        std::string objPath(spawnEnemy.objectPath);

        GE::ECS::Entity entity = this->entityManager->createEntity(objPath);
        GE::ECS::ComponentManager &componentManager = this->entityManager->getComponentManager();
        std::shared_ptr<GE::ECS::Components::Position> position = componentManager.getComponent<GE::ECS::Components::Position>(entity);
        position->set(GE::Utils::Vector2<float>(spawnEnemy.x, spawnEnemy.y));
    }

}