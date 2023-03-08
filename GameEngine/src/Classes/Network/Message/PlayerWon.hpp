#ifndef __RT_GE_NETWORK_MESSAGE_PLAYER_WON_HPP__
    #define __RT_GE_NETWORK_MESSAGE_PLAYER_WON_HPP__

namespace RT::GE::Network::Message {

    struct PlayerWon_s {
        int useless;

        PlayerWon_s(): useless(0) {};
    };

};

#endif