/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Timer.hpp
*/

#ifndef __RT_GAMEENGINE_LIB_SDL2_TIMER_HPP__
    #define __RT_GAMEENGINE_LIB_SDL2_TIMER_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include <SDL.h>

class RT::GE::Lib::SDL2::Timer {

    private:
        Uint64 previousTick;
        float elapsedSeconds;

    public:
        Timer();
        void tick();
        float getElapsedSeconds() const;
        Uint32 getTicks() const;
        Uint64 getPerformanceCounter() const;
        Uint64 getPerformanceFrequency() const;

};

#endif
