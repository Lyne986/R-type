#ifndef __RT_GAMEENGINE_NETWORK_MESSAGE_UDPINIT_HPP__
    #define __RT_GAMEENGINE_NETWORK_MESSAGE_UDPINIT_HPP__

    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct UDPInit_s {
        int port;
        int value = 0;

        UDPInit_s(int port = -1): port(port) {};
    };
}

#endif
