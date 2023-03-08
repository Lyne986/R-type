#ifndef __RT_SERVER_GAME_PARTY_HPP__
    #define __RT_SERVER_GAME_PARTY_HPP__

    #include "GameLogicNamespace.hpp"
    #include "Network/MyServer.hpp"
    #include "GameLogic/SpawnManager.hpp"
    #include <GameEngineNetwork.hpp>
    #include <GameEngineUtils.hpp>
    #include <memory>
    #include <unordered_map>

namespace RT::Server::GameLogic {
    class Party {
        private:
            std::unordered_map<int, std::shared_ptr<Connection<CustomMsgTypes>>> client = {};
            std::unordered_map<int, GE::Utils::Vector2<int>> playerPosition = {};
            int curr_pid = 0;
            std::shared_ptr<SpawnManager> spawnManager = nullptr;

            void sendToAllPlayers(int pid);

        public:
            Party();
            void addPlayer(std::shared_ptr<Connection<CustomMsgTypes>> client);
            void setPosition(int pid, GE::Utils::Vector2<int> position);
            void shoot(int pid, GE::Utils::Vector2<int> pos);
            void shoot(int pid);
            void disconnect(int pid);
            void disconnect(std::shared_ptr<Connection<CustomMsgTypes>> client);
            void update();
    };
}

#endif