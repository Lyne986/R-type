/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Timer.cpp
*/

#include "Timer.hpp"

namespace RT::GE::Lib::SDL2 {

    Timer::Timer()
    {
        this->elapsedSeconds = 0;
        this->previousTick = 0;
    }

    void Timer::tick()
    {
        const Uint64 currrentTick = this->getPerformanceCounter();
        const Uint64 delta = currrentTick - this->previousTick;
        this->previousTick = currrentTick;
        static const Uint64 TICKS_PER_SECOND = this->getPerformanceFrequency();
        if (delta != 0) {
            this->elapsedSeconds = delta / static_cast<float>(TICKS_PER_SECOND);
        }
    }

    float Timer::getElapsedSeconds() const
    {
        return this->elapsedSeconds;
    }

    Uint32 Timer::getTicks() const
    {
        return SDL_GetTicks();
    }

    Uint64 Timer::getPerformanceCounter() const
    {
        return SDL_GetPerformanceCounter();
    }

    Uint64 Timer::getPerformanceFrequency() const
    {
        return SDL_GetPerformanceFrequency();
    }
};