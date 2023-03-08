/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** JoinRoom
*/

#include "Network/Message/Parser/JoinRoom.hpp"

namespace RT::Server::Network::Message::Parser {

    JoinRoom::JoinRoom(MyServer &server) : AParser(server) {}

    void JoinRoom::parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) {
        std::cout << "JoinRoom" << std::endl;
        GE::Network::Message::JoinRoom JoinRoom;
        msg >> JoinRoom;
        this->server.joinRoom(client, JoinRoom.roomId);
    }
}