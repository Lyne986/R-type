#include "Parser.hpp"

namespace RT::Client::Network::Message::Parser {

    Parser::Parser(std::shared_ptr<GE::Scene::SceneManager> sceneManager)
    {
        this->joinMessage = std::make_shared<JoinMessage>(sceneManager);
        this->playerJoin = std::make_shared<PlayerJoin>(sceneManager);
        this->playerPosition = std::make_shared<PlayerPosition>(sceneManager);
        this->shootPos = std::make_shared<ShootPos>(sceneManager);
        this->playerDisconnect = std::make_shared<PlayerDisconnect>(sceneManager);
        this->udpInit = std::make_shared<UDPInit>(sceneManager);
        this->spawnEnemy = std::make_shared<SpawnEnemy>(sceneManager);
        this->playerWin = std::make_shared<PlayerWin>(sceneManager);
        this->listRoom = std::make_shared<ListRoom>(sceneManager);
        this->shoot = std::make_shared<Shoot>(sceneManager);
    }

    void Parser::parseMessage(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg)
    {
        this->changeScene();
        switch (msg.header.id) {
            case CustomMsgTypes::ServerMessage:
                this->parserServerMessage(client, msg);
                break;
            default:
                break;
        }
    }

    void Parser::parserServerMessage(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg)
    {
        std::string type = std::string(msg.header.type);

        if (type == "Join") {
            this->joinMessage->parse(client, msg);
        } else if (type == "PlayerJoin") {
            this->playerJoin->parse(client, msg);
        } else if (type == "PlayerPosition") {
            this->playerPosition->parse(client, msg);
        } else if (type == "ShootPos") {
            this->shootPos->parse(client, msg);
        } else if (type == "PlayerDisconnect") {
            this->playerDisconnect->parse(client, msg);
        } else if (type == "UDPInit") {
            this->udpInit->parse(client, msg);
        } else if (type == "SpawnEnemy") {
            this->spawnEnemy->parse(client, msg);
        } else if (type == "PlayerWin") {
            this->playerWin->parse(client, msg);
        } else if (type == "ListRoom") {
            this->listRoom->parse(client, msg);
        } else if (type == "Shoot") {
            this->shoot->parse(client, msg);
        }
    }

    void Parser::changeScene()
    {
        this->joinMessage->updateScene();
        this->playerJoin->updateScene();
        this->playerPosition->updateScene();
        this->shootPos->updateScene();
        this->playerDisconnect->updateScene();
        this->udpInit->updateScene();
        this->spawnEnemy->updateScene();
        this->playerWin->updateScene();
        this->shoot->updateScene();
    }

    std::shared_ptr<Parser> Parser::getInstance(std::shared_ptr<GE::Scene::SceneManager> sceneManager)
    {
        static std::shared_ptr<Parser> instance = std::make_shared<Parser>(sceneManager);

        return instance;
    }

}