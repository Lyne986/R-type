#ifndef __RT_GE_NETWORK_MESSAGE_PLAYERJOIN_HPP__
    #define __RT_GE_NETWORK_MESSAGE_PLAYERJOIN_HPP__

    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct PlayerJoin_s {
        int pid = -1;

        PlayerJoin_s(int pid = -1) : pid(pid) {}
    };
}

#endif
