#ifndef __RT_GE_NETWORK_MESSAGE_PLAYERDISCONNECT_HPP__
    #define __RT_GE_NETWORK_MESSAGE_PLAYERDISCONNECT_HPP__

    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct PlayerDisconnect_s {
        int pid;
        int gid = -1;

        PlayerDisconnect_s(int pid = -1, int gid = -1) : gid(gid), pid(pid) {}
    };
}

#endif