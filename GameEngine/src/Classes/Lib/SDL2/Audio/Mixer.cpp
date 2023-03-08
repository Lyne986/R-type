/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Mixer.cpp
*/

#include "Lib/SDL2/Audio/Mixer.hpp"

namespace RT::GE::Lib::SDL2::Audio {

    Mixer::Mixer(int frequency, Uint16 format, int channels, int chunksize, unsigned int nbChannels)
    {
        if (Mix_Init(MIX_INIT_OPUS) != 0) {
            throw Utils::Error("Mix_Init Error: " + std::string(Mix_GetError()));
        }
        if(Mix_OpenAudio(frequency, format, channels, chunksize) == -1) {
            throw Utils::Error("Mixer Error: " + std::string(Mix_GetError()));
        }
        if (Mix_AllocateChannels(nbChannels) == -1) {
            throw Utils::Error("Mixer Error: " + std::string(Mix_GetError()));
        }
    }

    Mixer::~Mixer()
    {
        Mix_CloseAudio();
        Mix_Quit();
    }
}
