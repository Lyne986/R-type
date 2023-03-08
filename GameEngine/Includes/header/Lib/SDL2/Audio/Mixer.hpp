/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Mixer.hpp
*/

#ifndef __LIB_SDL2_MIXER_HPP__
    #define __LIB_SDL2_MIXER_HPP__

    #include "Lib/SDL2Namespace.hpp"
    #include "Utils/Error.hpp"

    #include <SDL.h>
    #include <SDL_mixer.h>


class RT::GE::Lib::SDL2::Audio::Mixer {

    public:
        Mixer(int frequency = 44100, Uint16 format = MIX_DEFAULT_FORMAT, int channels = MIX_DEFAULT_CHANNELS, int chunksize = 1024, unsigned int nbChannels = 10);
        ~Mixer();

};

#endif
