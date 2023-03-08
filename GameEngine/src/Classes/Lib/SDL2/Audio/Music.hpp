/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Music.hpp
*/

#ifndef __LIB_SDL2_MUSIC_HPP__
    #define __LIB_SDL2_MUSIC_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Utils/Error.hpp"

    #include <SDL.h>
    #include <SDL_mixer.h>


class RT::GE::Lib::SDL2::Audio::Music {

    private:
        Mix_Music *music;

    public:
        Music(std::string filepath);
        ~Music();
        void play(int loops);

        static void pause();
        static void resume();
        static void rewind();
        static void stop();
        static int getVolume();
        static void setVolume(unsigned int volume);
        static bool isPaused();
        static bool isPlaying();

};

#endif
