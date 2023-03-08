#ifndef __RT_GE_ECS_COMPONENTS_BUTTONSOUND_HPP__
#define __RT_GE_ECS_COMPONENTS_BUTTONSOUND_HPP__

#include "ClientNamespace.hpp"
#include "ECSNamespace.hpp"
#include <GameEngineECS.hpp>
#include <GameEngineScene.hpp>
#include <GameEngineWindow.hpp>

class RT::Client::Components::ButtonSound
    : public RT::GE::ECS::Components::AComponent {

public:
    enum SoundType {
        MUSIC,
        SOUND
    };
    ButtonSound(SoundType type, int addSound, GE::Lib::SDL2::Window::Event &event);
    ~ButtonSound() {};

    void onClick();
    void getClick(GE::Utils::Vector2<int> pos, GE::Utils::Vector2<int> dim);

private:
    RT::Client::Components::ButtonSound::SoundType type;
    int newSound;
    GE::Lib::SDL2::Window::Event &event;
};

#endif
