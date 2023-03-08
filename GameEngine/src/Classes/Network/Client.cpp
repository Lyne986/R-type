/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** Client
*/

#include "Network/Client.hpp"

namespace RT::GE::Network::Client
{

    Client::Client()
    {
    }

    Client::~Client()
    {
    }

    void Client::pingServer()
    {
        // std::cout << "Pinging server..." << std::endl;
        message_s<CustomMsgTypes> msg;
        msg.header.id = CustomMsgTypes::ServerPing;

        std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();

        msg << timeNow;
        send(msg);
    }

    void Client::createRoom()
    {
        // std::cout << "creating room..." << std::endl;
        message_s<CustomMsgTypes> msg;
        msg.header.id = CustomMsgTypes::CreateRoom;

        std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();

        msg << timeNow;
        send(msg);
    }

    void Client::listRoom()
    {
        // std::cout << "Listing Room..." << std::endl;
        message_s<CustomMsgTypes> msg;
        msg.header.id = CustomMsgTypes::RoomList;

        std::chrono::system_clock::time_point timeNow = std::chrono::system_clock::now();

        msg << timeNow;
        send(msg);
    }

    void Client::messageAll()
    {
        message_s<CustomMsgTypes> msg;
        msg.header.id = CustomMsgTypes::messageAll;
        msg << "Hello from Client!";
        send(msg);
    }

}