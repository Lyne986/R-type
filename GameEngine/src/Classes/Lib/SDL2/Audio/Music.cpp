/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Music.cpp
*/

#include "Lib/SDL2/Audio/Music.hpp"

namespace RT::GE::Lib::SDL2::Audio {

    Music::Music(std::string filepath)
    {
        this->music = Mix_LoadMUS(filepath.c_str());
    }

    Music::~Music()
    {
        Mix_FreeMusic(this->music);
    }

    void Music::play(int loops)
    {
        Mix_PlayMusic(this->music, loops);
    }

    void Music::pause()
    {
        Mix_PauseMusic();
    }

    void Music::resume()
    {
        Mix_ResumeMusic();
    }

    void Music::rewind()
    {
        Mix_RewindMusic();
    }

    void Music::stop()
    {
        Mix_HaltMusic();
    }

    int Music::getVolume()
    {
        return Mix_VolumeMusic(-1);
    }

    void Music::setVolume(unsigned int volume)
    {
        Mix_VolumeMusic(volume);
    }

    bool Music::isPaused()
    {
        return Mix_PausedMusic();
    }

    bool Music::isPlaying()
    {
        return Mix_PlayingMusic();
    }

}
