/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Sound.cpp
*/

#include "Lib/SDL2/Audio/Sound.hpp"

namespace RT::GE::Lib::SDL2::Audio {

    Sound::Sound(std::string filepath)
    {
        this->sound = Mix_LoadWAV(filepath.c_str());
    }

    Sound::~Sound()
    {
        Mix_FreeChunk(this->sound);
    }

    void Sound::play(int channel, int loops)
    {
        Mix_PlayChannel(channel, this->sound, loops);
    }

    int Sound::getVolume()
    {
        return Mix_VolumeChunk(this->sound, -1);
    }

    int Sound::getVolume(int channel)
    {
        return Mix_Volume(channel, -1);
    }

    void Sound::setVolume(unsigned int volume)
    {
        Mix_VolumeChunk(this->sound, volume);
    }

    void Sound::setVolume(unsigned int channel, unsigned int volume)
    {
        Mix_Volume(channel, volume);
    }

    void Sound::pause(unsigned int channel)
    {
        Mix_Pause(channel);
    }

    void Sound::resume(unsigned int channel)
    {
        Mix_Resume(channel);
    }

    int Sound::isPaused(unsigned int channel)
    {
        return Mix_Paused(channel);
    }

    int Sound::isPlaying(unsigned int channel)
    {
        return Mix_Playing(channel);
    }


}
