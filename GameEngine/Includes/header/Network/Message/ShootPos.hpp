#ifndef __RT_GAMEENGINE_NETWORK_MESSAGE_SHOOTPOS_HPP__
    #define __RT_GAMEENGINE_NETWORK_MESSAGE_SHOOTPOS_HPP__

    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct ShootPos_s {
        int x, y;
        int pid;
        int gid;

        ShootPos_s(int pid = -1, int x = -1, int y = -1, int gid = -1)
        : x(x), y(y), pid(pid), gid(gid) {};
    };
}

#endif
