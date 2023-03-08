/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** SpawnManager.cpp
*/

#include "SpawnManager.hpp"

namespace RT::Server::GameLogic
{

    SpawnManager::SpawnManager(std::string levelPath)
    {
        RT::GE::Utils::JSON json(levelPath);
        nlohmann::json data = json.getData();

        std::srand(std::time(0));
        for (auto it = data.begin(); it != data.end(); ++it) {
            this->addWave(it.value());
        }
        this->currentWave = 0;
        this->currentLength = this->waves[this->currentWave].length;
        this->currentSpawnInterval = 1;
    }

    void SpawnManager::addWave(nlohmann::json waveData)
    {
        Wave wave;

        wave.length = waveData["length"];
        wave.spawnInterval = waveData["spawnInterval"];
        for (auto it = waveData["enemies"].begin(); it != waveData["enemies"].end(); ++it) {
            nlohmann::json enemyData = it.value();
            Enemy enemy = {enemyData["chance"], enemyData["src"]};

            wave.enemies.push_back(enemy);
        }
        this->waves.push_back(wave);
    }

    void SpawnManager::addPlayer(std::shared_ptr<Connection<CustomMsgTypes>> client, int pid)
    {
        this->client.insert({pid, client});
    }

    void SpawnManager::update()
    {
        static GE::Lib::SDL2::Timer timer;
        timer.tick();
        float deltaTime = timer.getElapsedSeconds();

        if (deltaTime > 1 || this->hasWon) {
            return;
        }
        this->currentLength -= deltaTime;
        if (this->currentLength <= 0) {
            if (this->currentWave < this->waves.size() - 1) {
                this->currentWave++;
                this->currentLength = this->waves[this->currentWave].length;
                this->currentSpawnInterval = 1;
            } else {
                this->hasWon = true;
                this->sendWin();
            }
        }
        this->currentSpawnInterval -= deltaTime;
        if (this->currentSpawnInterval <= 0) {
            this->spawnEnemy();
            this->currentSpawnInterval = this->waves[this->currentWave].spawnInterval;
        }
    }

    void SpawnManager::sendWin()
    {
        GE::Network::Message::PlayerWon won;
        message_s<CustomMsgTypes> msg("PlayerWin");
        msg.header.id = CustomMsgTypes::ServerMessage;
        msg << won;
        for (auto &it : this->client) {
            std::cout << "SENDING won" << std::endl;
            it.second->Send(msg);
        }
    }

    void SpawnManager::spawnEnemy()
    {
        int rand = std::rand() % 100;

        for (Enemy enemy : this->waves[this->currentWave].enemies) {
            if (rand <= enemy.chance) {
                RT::GE::Utils::JSON json(enemy.objectPath);
                RT::GE::Utils::JSON dataJson(json.getData()["enemy"]);
                nlohmann::json data = dataJson.getData();

                if (data["spawnPos"] != nullptr) {
                    int minY = data["spawnPos"]["minY"];
                    int maxY = data["spawnPos"]["maxY"];
                    int x = data["spawnPos"]["x"];
                    int randY = std::rand() % (maxY - minY + 1) + minY;
                    GE::Utils::Vector2<float> pos(x, randY);
                    this->sendSpawnToClient(enemy.objectPath, pos, this->lastId);
                    this->lastId++;
                }
            } else {
                rand -= enemy.chance;
            }
        }
    }

    void SpawnManager::sendSpawnToClient(std::string path, GE::Utils::Vector2<float> position, int id)
    {
        GE::Network::Message::SpawnEnemy info(id, path, position);
        message_s<CustomMsgTypes> msg("SpawnEnemy");
        msg.header.id = CustomMsgTypes::ServerMessage;
        msg << info;
        std::cout << "=== START SENDING ===" << std::endl;
        for (auto it : this->client) {
            it.second->Send(msg);
            std::cout << "SENDING" << std::endl;
            std::cout << "info " << info.id << " " << info.objectPath << " " << info.x << " " << info.y << std::endl;
        }
        std::cout << "=== END SENDING ===" << std::endl;
    }

}