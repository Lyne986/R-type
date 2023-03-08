#ifndef __RT_GE_NETWORK_MESSAGE_PLAYERLEAVE_HPP__
    #define __RT_GE_NETWORK_MESSAGE_PLAYERLEAVE_HPP__
 
    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct PlayerLeave_s {
        int pid = -1;

        PlayerLeave_s(int pid = -1) : pid(pid) {}
    };
}

#endif