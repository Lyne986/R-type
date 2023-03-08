/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Rect.hpp
*/

#ifndef __PA_LIB_SDL2_RECT_HPP__
    #define __PA_LIB_SDL2_RECT_HPP__

    #include "Lib/SDL2Namespace.hpp"

    #include <SDL.h>


class RT::GE::Lib::SDL2::Graphic::Rect {

    private:
        SDL_Rect rect = {0, 0, 0, 0};

    public:
        Rect(int x, int y, int width, int height);
        SDL_Rect &getRect();
        void setRect(int x, int y, int width, int height);
        void setRectPosition(int x, int y);
        bool isOverlapping(SDL_Rect a, SDL_Rect b);

};

#endif
