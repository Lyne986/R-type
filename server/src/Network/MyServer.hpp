#ifndef __RT_SERVER_NETWORK_SERVER_HPP__
    #define __RT_SERVER_NETWORK_SERVER_HPP__

    #include <GameEngineNetwork.hpp>
    #include <functional>
    #include <memory>
    #include "../NetworkNamespace.hpp"
    #include <GameEngineNetwork.hpp>
    #include "Rooms.hpp"
    #include "GameLogic/PartyManager.hpp"

class RT::Server::Network::MyServer : public RT::GE::Network::Server::Server {
    public:
        MyServer(uint16_t nPort);
        void onMessage(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg);
        void onMessageUdp(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg);
        void setOnMessage(std::function<void(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)> onMessage);
        void setOnMessageUdp(std::function<void(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)> onMessage);
        void listRooms(std::shared_ptr<Connection<CustomMsgTypes>> client);
        void createRoom(std::shared_ptr<Connection<CustomMsgTypes>> client, std::string name = "");
        // void destroyRoom(std::shared_ptr<Rooms> room);
        void joinRoom(std::shared_ptr<Connection<CustomMsgTypes>> client, int id);
        void leaveRoom(std::shared_ptr<Connection<CustomMsgTypes>> client, std::string name);

    private:
        std::vector<std::pair<int, std::shared_ptr<Rooms>>> _rooms;
        int _RoomCounter = 1;
        std::function<void(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes> &msg)> onMessageCallback = nullptr;
        std::function<void(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)> onMessageCallbackUdp = nullptr;
        void onDisconnect(std::shared_ptr<Connection<CustomMsgTypes>> client);
        std::shared_ptr<RT::Server::GameLogic::PartyManager> partyManager = std::make_shared<RT::Server::GameLogic::PartyManager>();

};

#endif
