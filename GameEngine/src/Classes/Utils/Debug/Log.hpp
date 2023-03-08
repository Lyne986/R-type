/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Log.hpp
*/

#ifndef __RT_GE_UTILS_DEBUG_LOG_HPP__
    #define __RT_GE_UTILS_DEBUG_LOG_HPP__

    #include "UtilsNamespace.hpp"
    #include <string>
    #include <iostream>
    #include <set>
    #include <algorithm>

    #define IS_DEBUG        true

namespace RT::GE::Utils::Debug {

    class Log {

        public:
            enum MessageType {
                GameEngine,
                CollisionSystem,
                ClientNetwork,
                ServerNetwork,
                Player,
                Event,
                Network
            };

            static void LogMessage(MessageType tag, std::string message);
    };

    static const std::set<Log::MessageType> debugFlags = {Log::Event, Log::GameEngine, Log::Player, Log::CollisionSystem, Log::Network, Log::ClientNetwork, Log::ServerNetwork};
}


#endif