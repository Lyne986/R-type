/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Error.hpp
*/

#ifndef __RT_GE_UTILS_ERROR_HPP__
    #define __RT_GE_UTILS_ERROR_HPP__

    #include <stdexcept>
    #include <string>
    #include "UtilsNamespace.hpp"

class RT::GE::Utils::Error : public std::exception {
    private:
        std::string message;

    public:
        Error(const std::string &message);
        const char *what() const noexcept;
};

#endif