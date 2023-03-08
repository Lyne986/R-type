#ifndef __RT_SERVER_NETWORK_MESSAGE_PARSER_PARSER_HPP__
    #define __RT_SERVER_NETWORK_MESSAGE_PARSER_PARSER_HPP__

    #include "NetworkNamespace.hpp"
    #include "Network/Message/Parser/JoinMessage.hpp"
    #include "Network/Message/Parser/PlayerJoin.hpp"
    #include "Network/Message/Parser/PlayerPosition.hpp"
    #include "Network/Message/Parser/ShootPos.hpp"
    #include "Network/Message/Parser/PlayerDisconnect.hpp"
    #include "Network/Message/Parser/UDPInit.hpp"
    #include "Network/Message/Parser/SpawnEnemy.hpp"
    #include "Network/Message/Parser/PlayerWin.hpp"
    #include "Network/Message/Parser/ListRoom.hpp"
    #include "Network/Message/Parser/Shoot.hpp"
    #include <GameEngineNetwork.hpp>
    #include <GameEngineScene.hpp>

namespace RT::Client::Network::Message::Parser {
    class Parser {
        private:
            std::shared_ptr<JoinMessage> joinMessage;
            std::shared_ptr<PlayerJoin> playerJoin;
            std::shared_ptr<PlayerPosition> playerPosition;
            std::shared_ptr<ShootPos> shootPos;
            std::shared_ptr<PlayerDisconnect> playerDisconnect;
            std::shared_ptr<UDPInit> udpInit;
            std::shared_ptr<SpawnEnemy> spawnEnemy;
            std::shared_ptr<PlayerWin> playerWin;
            std::shared_ptr<ListRoom> listRoom;
            std::shared_ptr<Shoot> shoot;

            void parserServerMessage(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);

        public:
            Parser(std::shared_ptr<GE::Scene::SceneManager> sceneManager);
            void parseMessage(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg);
            void changeScene();
            static std::shared_ptr<Parser> getInstance(std::shared_ptr<GE::Scene::SceneManager> sceneManager = nullptr);
    };
}

#endif