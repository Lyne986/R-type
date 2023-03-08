#include "Parser.hpp"

namespace RT::Server::Network::Message::Parser {

    Parser::Parser(MyServer &server)
    : server(server), joinMessage(server), playerPosition(server),
    playerDisconnect(server), createRoom(server),
    joinRoom(server), listRoom(server),
    shootPos(server), shoot(server) {}

    void Parser::parseMessage(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg)
    {
        std::string type = std::string(msg.header.type);

        if (type == "Join") {
            this->joinMessage.parse(client, msg);
        } else if (type == "PlayerPosition") {
            this->playerPosition.parse(client, msg);
        } else if (type == "ShootPos") {
            this->shootPos.parse(client, msg);
        } else if (type == "PlayerDisconnect") {
            this->playerDisconnect.parse(client, msg);
        } else if (type == "CreateRoom") {
            this->createRoom.parse(client, msg);
        } else if (type == "JoinRoom") {
            this->joinRoom.parse(client, msg);
        } else if (type == "ListRoom") {
            this->listRoom.parse(client, msg);
        } else if (type == "UDPInit") {
            // std::cout << "UDPInit received" << std::endl;
        } else if (type == "Shoot") {
            this->shoot.parse(client, msg);
        }
    }
}