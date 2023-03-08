#ifndef __RT_GE_NETWORK_MESSAGE_JOINMESSAGE_HPP__
    #define __RT_GE_NETWORK_MESSAGE_JOINMESSAGE_HPP__

    #include "NetworkNamespace.hpp"

namespace RT::GE::Network::Message {
    struct JoinMessage_s {
        int pid = -1;
        int party = 1;

        JoinMessage_s(int pid = -1, int party = -1) : pid(pid), party(party) {}
    };
}

#endif
