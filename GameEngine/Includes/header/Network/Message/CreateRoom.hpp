/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** CreateRoom
*/

#ifndef __RT_GE_NETWORK_MESSAGE_CREATEROOM_HPP__
    #define __RT_GE_NETWORK_MESSAGE_CREATEROOM_HPP__

    #include "NetworkNamespace.hpp"
    #include <string>
    #include <cstring>

namespace RT::GE::Network::Message {
    struct CreateRoom_s {
        char name[32];

        CreateRoom_s(std::string name = "Default")
        {
            std::memset(this->name, 0, 32);
            std::memcpy(this->name, name.c_str(), name.size());
        }
    };
}

#endif