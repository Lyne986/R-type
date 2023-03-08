/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Log.cpp
*/

#include "Utils/Debug/Log.hpp"

namespace RT::GE::Utils::Debug {

    void Log::LogMessage(Log::MessageType tag, std::string message)
    {
        if (IS_DEBUG && debugFlags.find(tag) != debugFlags.end()) {
            // std::cout << message << std::endl;
        }
    }

}