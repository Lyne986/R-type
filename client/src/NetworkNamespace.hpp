#ifndef __RT_CLIENT_NETWORK_NAMESPACE_HPP__
    #define __RT_CLIENT_NETWORK_NAMESPACE_HPP__

namespace RT::Client {
    class SingletonIdRoom;
    namespace Network {
        class SingletonClient;
        namespace Message {
            namespace Parser {
                class Parser;
                class IParser;
                class AParser;
                class PlayerJoin;
                class JoinMessage;
                class ShootPos;
                class UDPInit;
                class PlayerPosition;
                class PlayerDisconnect;
                class SpawnEnemy;
                class PlayerWin;
                class ListRoom;
                class Shoot;
            }
        }
    }
}

#endif