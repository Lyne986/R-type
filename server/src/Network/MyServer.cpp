#include "MyServer.hpp"

namespace RT::Server::Network {

    MyServer::MyServer(uint16_t port)
    : Server(port)
    {
    }

    void MyServer::setOnMessage(std::function<void(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)> onMessage) {
        this->onMessageCallback = onMessage;
    }

    void MyServer::setOnMessageUdp(std::function<void(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)> onMessage) {
        this->onMessageCallbackUdp = onMessage;
    }

    void MyServer::onMessage(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)
    {
        if (this->onMessageCallback != nullptr) {
            this->onMessageCallback(client, msg);
        }
    }

    void MyServer::onMessageUdp(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)
    {
        if (this->onMessageCallbackUdp != nullptr) {
            this->onMessageCallbackUdp(client, msg);
        }
    }

    void MyServer::listRooms(std::shared_ptr<Connection<CustomMsgTypes>> client)
    {
        int count = 1;
        for (auto room : _rooms) {
            GE::Network::Message::ListRoom listRooms(room.first, room.second->getName(), room.second->getNbClients(), _rooms.size(), count);

            message_s<CustomMsgTypes> msg("ListRoom");
            msg.header.id = CustomMsgTypes::ServerMessage;

            msg << listRooms;

            sendMessage(client, msg);
        }
    }

    void MyServer::createRoom(std::shared_ptr<Connection<CustomMsgTypes>> client, std::string name)
    {
        std::shared_ptr<Rooms> room = std::make_shared<Rooms>(client, _RoomCounter, name);
        _rooms.push_back(std::pair<int, std::shared_ptr<Rooms>>(_RoomCounter, room));
        _RoomCounter++;
    }

    // void MyServer::destroyRoom(std::shared_ptr<Rooms> room)
    // {
    //     _rooms.erase(std::remove(_rooms.begin(), _rooms.end(), room), _rooms.end());
    // }

    void MyServer::joinRoom(std::shared_ptr<Connection<CustomMsgTypes>> client, int id)
    {
        std::cout << "Join Room" << std::endl;
        for (std::pair<int, std::shared_ptr<Rooms>> &room : _rooms) {
            if (room.second->getId() == id) {
                room.second->addClient(client);
                return;
            }
        }
    }

    void MyServer::leaveRoom(std::shared_ptr<Connection<CustomMsgTypes>> client, std::string name)
    {
        for (std::pair<int, std::shared_ptr<Rooms>> &room : _rooms) {
            if (room.second->getName() == name) {
                room.second->removeClient(client);
                return;
            }
        }
    }

    void MyServer::onDisconnect(std::shared_ptr<Connection<CustomMsgTypes>> client)
    {
        std::cout << "Removing client " << client->GetID() << std::endl;
        this->partyManager->disconnect(client);
    }

}
