#ifndef __RT_GE_NETWORK_MESSAGE_PLAYERPOSITION_HPP__
    #define __RT_GE_NETWORK_MESSAGE_PLAYERPOSITION_HPP__
 
    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct PlayerPosition_s {
        int pid = -1;
        int x = 0;
        int y = 0;
        int gid = -1;

        PlayerPosition_s(int pid = -1, int x = 0, int y = 0, int gid = -1) : pid(pid), x(x), y(y), gid(gid) {}
    };
}

#endif