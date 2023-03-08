#ifndef __RT_GE_NETWORK_MESSAGE_SPAWN_ENEMY_HPP__
    #define __RT_GE_NETWORK_MESSAGE_SPAWN_ENEMY_HPP__

    #include "NetworkNamespace.hpp"
    #include "Utils/Vector2.hpp"

    #define MAX_OBJECT_PATH 256

namespace RT::GE::Network::Message {
    struct SpawnEnemy_s {
        int id;
        char objectPath[MAX_OBJECT_PATH];
        float x;
        float y;

        SpawnEnemy_s(int id, std::string objectPath, float x, float y): id(id), x(x), y(y)
        {
            std::strcpy(this->objectPath, objectPath.c_str());
        }

        SpawnEnemy_s(int id, std::string objectPath, GE::Utils::Vector2<float> position): id(id), x(position.x), y(position.y)
        {
            std::strcpy(this->objectPath, objectPath.c_str());
        }

        SpawnEnemy_s(): id(0), x(0), y(0)
        {
            std::strcpy(this->objectPath, "");
        }
    };
}

#endif
