/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Rect.cpp
*/

#include "Lib/SDL2/Graphic/Rect.hpp"

namespace RT::GE::Lib::SDL2::Graphic {

    Rect::Rect(int x, int y, int width, int height)
    {
        this->setRect(x, y, width, height);
    }

    SDL_Rect &Rect::getRect()
    {
        return this->rect;
    }

    void Rect::setRect(int x, int y, int width, int height)
    {
        this->rect = {x, y, width, height};
    }

    void Rect::setRectPosition(int x, int y)
    {
        this->rect = {x, y, this->rect.w, this->rect.h};
    }

    bool Rect::isOverlapping(SDL_Rect a, SDL_Rect b)
    {
        int leftA = a.x;
        int topA = a.y;
        int rightA = a.x + a.w;
        int bottomA = a.y + a.h;

        int leftB = b.x;
        int topB = b.y;
        int rightB = b.x + b.w;
        int bottomB = b.y + b.h;

        if (topA > bottomB || topB > bottomA) {
            return false;
        }

        if (leftA > rightB || leftB > rightA) {
            return false;
        }

        return true;
    }

}