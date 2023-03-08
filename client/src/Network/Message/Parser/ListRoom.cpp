/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** ListRoom
*/

#include "Network/Message/Parser/ListRoom.hpp"

namespace RT::Client::Network::Message::Parser {

    ListRoom::ListRoom(std::shared_ptr<GE::Scene::SceneManager> sceneManager)
    : AParser(sceneManager)
    {
    }

    void ListRoom::parse(std::shared_ptr<RT::GE::Network::Client::Client> client, message_s<CustomMsgTypes> msg)
    {
        RT::GE::Network::Message::ListRoom listRoom;
        msg >> listRoom;

        std::shared_ptr<GE::Scene::AScene> scene = sceneManager->getCurr();
        std::shared_ptr<RT::Client::Scenes::RoomScene> roomScene = std::dynamic_pointer_cast<RT::Client::Scenes::RoomScene>(scene);
        // std::cout << "ListRoom size -> " << listRoom.rooms.size() << std::endl;
        if (roomScene) {
            roomScene->setRooms(listRoom);
        }

    }

}