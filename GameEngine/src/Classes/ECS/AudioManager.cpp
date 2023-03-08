/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** AudioManager.cpp
*/

#include "ECS/AudioManager.hpp"

namespace RT::GE::ECS {

    AudioManager::AudioManager()
    {
        this->mixer = std::make_unique<Lib::SDL2::Audio::Mixer>();
        this->globalmusicVolume = 64;
        this->globalsoundVolume = 64;
    }

    AudioManager::~AudioManager()
    {

    }

    std::shared_ptr<AudioManager> AudioManager::getInstance()
    {
        static std::shared_ptr<AudioManager> instance = std::make_shared<AudioManager>();
        return (instance);
    }

    void AudioManager::changeMusicVolume(int volume)
    {
        this->globalmusicVolume = volume;
        for (auto &music : this->musics) {
            music.second->setVolume(volume);
        }
    }

    void AudioManager::changeSoundVolume(int volume)
    {
        this->globalsoundVolume = volume;
        for (auto &sound : this->sounds) {
            sound.second->setVolume(volume);
        }
    }

    int AudioManager::getMusicVolume() const
    {
        return (this->globalmusicVolume);
    }

    int AudioManager::getSoundVolume() const
    {
        return (this->globalsoundVolume);
    }

    void AudioManager::addMusic(std::string name, std::string musicPath)
    {
        if (this->musics.find(name) == this->musics.end()) {
            this->musics[name] = std::make_shared<Lib::SDL2::Audio::Music>(musicPath);
            this->musics[name]->setVolume(this->globalmusicVolume);
        } else {
            throw Utils::Error("Music already exists");
        }
    }

    void AudioManager::addSound(std::string name, std::string soundPath)
    {
        if (this->sounds.find(name) == this->sounds.end()) {
            this->sounds[name] = std::make_shared<Lib::SDL2::Audio::Sound>(soundPath);
            this->sounds[name]->setVolume(this->globalsoundVolume);
        } else {
            throw Utils::Error("Sound already exists");
        }
    }

    std::shared_ptr<Lib::SDL2::Audio::Music> AudioManager::getMusic(std::string name)
    {
        if (this->musics.find(name) == this->musics.end()) {
            throw Utils::Error("Music doesn't exist");
        } else {
            return this->musics[name];
        }
    }

    std::shared_ptr<Lib::SDL2::Audio::Sound> AudioManager::getSound(std::string name)
    {
        if (this->sounds.find(name) == this->sounds.end()) {
            throw Utils::Error("Sound doesn't exist");
        } else {
            return this->sounds[name];
        }
    }

}
