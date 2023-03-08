/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** AudioManager.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_AUDIOMANAGER_HPP__
    #define __RT_GAMEENGINE_ECS_AUDIOMANAGER_HPP__

    #include "ECSNamespace.hpp"
    #include "Lib/SDL2/Audio/Mixer.hpp"
    #include "Lib/SDL2/Audio/Music.hpp"
    #include "Lib/SDL2/Audio/Sound.hpp"
    #include "Utils/Error.hpp"

    #include <unordered_map>
    #include <memory>

class RT::GE::ECS::AudioManager {

    private:
        std::unordered_map<std::string, std::shared_ptr<Lib::SDL2::Audio::Music>> musics;
        std::unordered_map<std::string, std::shared_ptr<Lib::SDL2::Audio::Sound>> sounds;
        std::unique_ptr<Lib::SDL2::Audio::Mixer> mixer;
        int globalmusicVolume;
        int globalsoundVolume;

    public:
        AudioManager();
        ~AudioManager();
        static std::shared_ptr<AudioManager> getInstance();

        void changeMusicVolume(int volume);
        void changeSoundVolume(int volume);
        int getMusicVolume() const;
        int getSoundVolume() const;
        void addMusic(std::string name, std::string musicPath);
        void addSound(std::string name, std::string soundPath);
        std::shared_ptr<Lib::SDL2::Audio::Music> getMusic(std::string name);
        std::shared_ptr<Lib::SDL2::Audio::Sound> getSound(std::string name);
};

#endif
