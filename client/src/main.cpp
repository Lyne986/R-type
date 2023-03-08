/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** main.cpp
*/

#define SDL_MAIN_HANDLED
#include "main.hpp"

int main(void)
{
    try {
        RT::Client::Core core;

        core.init();
        core.run();
    } catch (RT::GE::Utils::Error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}
