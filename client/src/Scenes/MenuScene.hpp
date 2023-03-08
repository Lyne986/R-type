#ifndef __RT_CLIENT_OBJECT_SCENE_MENU_HPP__
    #define __RT_CLIENT_OBJECT_SCENE_MENU_HPP__

    #include "ClientNamespace.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/ButtonScene.hpp"
    #include "Systems/ClickButtonSceneSystem.hpp"
    #include "Network/Message/Parser/Parser.hpp"
    #include "Systems/ReleaseButtonSceneSystem.hpp"
    #include "Systems/HoverButtonSceneSystem.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineScene.hpp>
    #include <GameEngineRendering.hpp>
    #include <GameEngineInput.hpp>
    #include <GameEngineWindow.hpp>
    #include <memory>

class RT::Client::Scenes::MenuScene : public GE::Scene::AScene
{
private:
    std::shared_ptr<Network::Message::Parser::Parser> parser = Client::Network::Message::Parser::Parser::getInstance();

public:
    MenuScene(GE::Lib::SDL2::Window::Event& event, GE::Lib::SDL2::Graphic::Renderer& renderer, std::string objectsPath);
    void registerComponents();
    void update();
    void render();
    void init();
};

#endif