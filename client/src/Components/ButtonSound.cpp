#include "ButtonSound.hpp"

namespace RT::Client::Components {
    ButtonSound::ButtonSound(RT::Client::Components::ButtonSound::SoundType type, int newSound, GE::Lib::SDL2::Window::Event &event)
    : AComponent("buttonsound"), event(event)
    {
        this->newSound = newSound;
        this->type = type;
    }

    void ButtonSound::onClick()
    {
        if (this->type == RT::Client::Components::ButtonSound::SoundType::MUSIC) {
            int newVolume = GE::ECS::AudioManager::getInstance()->getMusicVolume() + this->newSound;; 
            GE::ECS::AudioManager::getInstance()->changeMusicVolume(newVolume);
        } else {
            int newVolume = GE::ECS::AudioManager::getInstance()->getSoundVolume() + this->newSound;
            GE::ECS::AudioManager::getInstance()->changeSoundVolume(newVolume);
        }
    }

    void ButtonSound::getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim)
    {
        // std::cout << "ButtonSound::getClick" << std::endl;
        if (this->event.getMousePosition().x >= pos.x && this->event.getMousePosition().x <= pos.x + dim.x && this->event.getMousePosition().y >= pos.y && this->event.getMousePosition().y <= pos.y + dim.y) {
            if (this->event.isLeftClick()) {
                // std::cout << "ButtonSound::getClick::onClick" << std::endl;
                this->onClick();
            }
        }
    }
}
