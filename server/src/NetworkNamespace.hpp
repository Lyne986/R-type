#ifndef __RT_SERVER_NETWORK_NAMESPACE_HPP__
    #define __RT_SERVER_NETWORK_NAMESPACE_HPP__

namespace RT::Server {
    namespace Network {
        class MyServer;
        class SingletonServer;
        class Rooms;
        namespace Message {
            class JoinMessage;
            namespace Parser {
                class AParser;
                class Parser;
                class JoinMessage;
                class PlayerPosition;
                class PlayerDisconnect;
                class ShootPos;
                class UDPInit;
                class CreateRoom;
                class Shoot;
            }
        }
    }
}

#endif