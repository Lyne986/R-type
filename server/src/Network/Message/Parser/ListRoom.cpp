/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** CreateRoom
*/

#include "Network/Message/Parser/CreateRoom.hpp"

namespace RT::Server::Network::Message::Parser {

    CreateRoom::CreateRoom(MyServer &server) : AParser(server) {}

    void CreateRoom::parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) {
        std::cout << "CreateRoom" << std::endl;
        GE::Network::Message::CreateRoom CreateRoom;
        msg >> CreateRoom;
        this->server.createRoom(client, CreateRoom.name);
    }
}