/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Core.hpp
*/

#ifndef __RT_GAMEENGINE_CORE_HPP__
    #define __RT_GAMEENGINE_CORE_HPP__

    #include "ClientNamespace.hpp"

    #include "Scenes/GameScene.hpp"
    #include "Scenes/MenuScene.hpp"
    #include "Scenes/OptionScene.hpp"
    #include "Scenes/RoomScene.hpp"
    #include "Network/Client.hpp"
    #include "Network/SingletonClient.hpp"
    #include "Network/Message/Parser/Parser.hpp"
    #include "Utils/Debug/Log.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineScene.hpp>
    #include <GameEngineRendering.hpp>
    #include <GameEngineInput.hpp>
    #include <GameEngineWindow.hpp>
    #include <GameEngineNetwork.hpp>
    #include <string>

    #define UPDATE_FREQUENCY    120
    #define CYCLE_TIME          (1.0f / UPDATE_FREQUENCY)

class RT::Client::Core {
    private:
        std::shared_ptr<RT::GE::Network::Client::Client> client = Network::SingletonClient::getInstance();
        RT::GE::Lib::SDL2::SDL2 sdl2;
        RT::GE::Lib::SDL2::Window::Window window;
        RT::GE::Lib::SDL2::Graphic::Renderer renderer;
        RT::GE::Lib::SDL2::Window::Event event;
        std::shared_ptr<RT::GE::Scene::SceneManager> sceneManager;
        std::shared_ptr<Network::Message::Parser::Parser> parser;

        void networkUpdate();
        void networkMessageParsing();

    public:
        Core();
        void init();
        void run();
};

#endif
