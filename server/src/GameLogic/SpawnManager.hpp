/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.nini
** File description:
** SpawnManager.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_SPAWN_MANAGER_HPP__
    #define __RT_GE_ECS_COMPONENTS_SPAWN_MANAGER_HPP__

    #include "GameLogicNamespace.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineRendering.hpp>
    #include <GameEngineNetwork.hpp>
    #include <GameEngineUtils.hpp>

namespace RT::Server::GameLogic {
    class SpawnManager {

        private:
            std::unordered_map<int, std::shared_ptr<Connection<CustomMsgTypes>>> client = {};
            int lastId = 0;
            struct Enemy {
                float chance;
                std::string objectPath;
            };

            struct Wave {
                float length;
                float spawnInterval;
                std::vector<Enemy> enemies;
            };

        std::vector<Wave> waves;
        unsigned int currentWave;
        float currentLength;
        float currentSpawnInterval;
        void addWave(nlohmann::json waveData);
        void spawnEnemy();
        void setRandomPosition(GE::ECS::ComponentManager &componentManager, GE::ECS::Entity enemy, std::string dataPath);
        void sendSpawnToClient(std::string path, GE::Utils::Vector2<float> position, int id);
        void sendWin();
        bool hasWon = false;

        public:
            SpawnManager(std::string levelPath = "assets/objects/data/level1.json");
            ~SpawnManager() {};
            void update();
            void addPlayer(std::shared_ptr<Connection<CustomMsgTypes>> client, int pid);
    };
}

#endif