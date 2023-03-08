#ifndef __RT_GE_NETWORK_NAMESPACE_HPP__
    #define __RT_GE_NETWORK_NAMESPACE_HPP__

namespace RT::GE::Network {
    namespace Server {
        class Server;
        template <typename T>
        class AServer;
        template <typename T>
        class IServer;
    };
    namespace Message {
        typedef struct JoinMessage_s JoinMessage;
        typedef struct PlayerJoin_s PlayerJoin;
        typedef struct PlayerPosition_s PlayerPosition;
        typedef struct PlayerLeave_s PlayerLeave;
        typedef struct ShootPos_s ShootPos;
        typedef struct PlayerDisconnect_s PlayerDisconnect;
        typedef struct UDPInit_s UDPInit;
        typedef struct SpawnEnemy_s SpawnEnemy;
        typedef struct PlayerWon_s PlayerWon;
        typedef struct CreateRoom_s CreateRoom;
        typedef struct JoinRoom_s JoinRoom;
        typedef struct ListRoom_s ListRoom;
        typedef struct Shoot_s Shoot;
    };
    namespace Client {
        class Client;
        template <typename T>
        class AClient;
    };
};

#endif