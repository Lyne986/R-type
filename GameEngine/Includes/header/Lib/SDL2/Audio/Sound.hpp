/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Sound.hpp
*/

#ifndef __LIB_SDL2_SOUND_HPP__
    #define __LIB_SDL2_SOUND_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Utils/Error.hpp"

    #include <SDL.h>
    #include <SDL_mixer.h>


class RT::GE::Lib::SDL2::Audio::Sound {

    private:
        Mix_Chunk *sound;

    public:
        Sound(std::string filepath);
        ~Sound();
        void play(int channel = -1, int loops = 0);
        void setVolume(unsigned int volume);
        int getVolume();

        static int getVolume(int channel);
        static void setVolume(unsigned int channel, unsigned int volume);
        static void pause(unsigned int channel);
        static void resume(unsigned int channel);
        static int isPaused(unsigned int channel);
        static int isPlaying(unsigned int channel);

};

#endif
