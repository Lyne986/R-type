/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** JoinRoom
*/

#ifndef __RT_GE_NETWORK_MESSAGE_JOINROOM_HPP__
    #define __RT_GE_NETWORK_MESSAGE_JOINROOM_HPP__

    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct JoinRoom_s {
        int roomId;

        JoinRoom_s(int roomId = -1): roomId(roomId) {};
    };
}

#endif