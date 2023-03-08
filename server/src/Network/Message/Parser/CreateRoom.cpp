/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** ListRoom
*/

#include "Network/Message/Parser/ListRoom.hpp"

namespace RT::Server::Network::Message::Parser {

    ListRoom::ListRoom(MyServer &server) : AParser(server) {}

    void ListRoom::parse(std::shared_ptr<Connection<CustomMsgTypes>> client, message_s<CustomMsgTypes>& msg) {
        this->server.listRooms(client);
    }
}