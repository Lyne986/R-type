/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Error.cpp
*/

#include "Utils/Error.hpp"

namespace RT::GE::Utils {

    Error::Error(const std::string &message): message(message) {

    }

    const char *Error::what(void) const noexcept {
        return (this->message.c_str());
    }

}