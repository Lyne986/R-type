/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** ListRoom
*/

#ifndef __RT_GE_NETWORK_MESSAGE_LISTROOM_HPP__
    #define __RT_GE_NETWORK_MESSAGE_LISTROOM_HPP__

    #include "NetworkNamespace.hpp"
    #include <string>
    #include <cstring>

namespace RT::GE::Network::Message {
    struct ListRoom_s {
        int id;
        char name[32];
        int nbPlayer;
        int nbrRooms;
        int count;

        ListRoom_s(int id = -1, std::string name = "Default", int nbPlayer = -1, int nbrRooms = -1, int count = -1)
        {
            this->id = id;
            std::memset(this->name, 0, 32);
            std::memcpy(this->name, name.c_str(), name.size());
            this->nbPlayer = nbPlayer;
            this->nbrRooms = nbrRooms;
            this->count = count;
        };
    };
}

#endif