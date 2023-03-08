#ifndef __RT_CLIENT_OBJECT_SCENE_OPTION_HPP__
    #define __RT_CLIENT_OBJECT_SCENE_OPTION_HPP__

    #include "ClientNamespace.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/ButtonScene.hpp"
    #include "Components/ChangeKey.hpp"
    #include "Components/ButtonSound.hpp"
    #include "Systems/ClickButtonSceneSystem.hpp"
    #include "Systems/ReleaseButtonSceneSystem.hpp"
    #include "Systems/HoverButtonSceneSystem.hpp"
    #include "Systems/ChangeKeySystem.hpp"
    #include "Systems/ChangeSoundSystem.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineScene.hpp>
    #include <GameEngineRendering.hpp>
    #include <GameEngineInput.hpp>
    #include <GameEngineWindow.hpp>
    #include <memory>

class RT::Client::Scenes::OptionScene : public GE::Scene::AScene
{
public:
    OptionScene(GE::Lib::SDL2::Window::Event& event, GE::Lib::SDL2::Graphic::Renderer& renderer, std::string objectsPath);
    void registerComponents();
    void update();
    void render();
    void init();
};

#endif
