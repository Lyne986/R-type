    #ifndef __RT_GE_NETWORK_MESSAGE_SHOOT_HPP__
    #define __RT_GE_NETWORK_MESSAGE_SHOOT_HPP__

    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct Shoot_s {
        int pid;
        int id;

        Shoot_s(int id = 0, int pid = 1)
        : pid(pid), id(id) {}
    };
}

#endif