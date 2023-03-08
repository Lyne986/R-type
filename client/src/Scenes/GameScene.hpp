#ifndef __RT_CLIENT_OBJECT_SCENE_HOME_HPP__
    #define __RT_CLIENT_OBJECT_SCENE_HOME_HPP__

    #include "ClientNamespace.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/OnlinePlayer.hpp"
    #include "Components/MainPlayer.hpp"
    #include "Components/Enemy.hpp"
    #include "Components/Score.hpp"

    #include "Systems/InputSystem.hpp"
    #include "Systems/HealthSystem.hpp"
    #include "Systems/OnlinePlayer.hpp"
    #include "Systems/MainPlayer.hpp"
    #include "Systems/EnemySystem.hpp"
    #include "Systems/ScoreSystem.hpp"

    #include "Transitions/GameStart.hpp"
    #include "Transitions/GameOver.hpp"
    #include "Transitions/GameWon.hpp"
    #include "Network/SingletonClient.hpp"

    #include <GameEngineECS.hpp>
    #include <GameEngineScene.hpp>
    #include <GameEngineRendering.hpp>
    #include <GameEngineInput.hpp>
    #include <GameEngineWindow.hpp>
    #include <GameEngineNetwork.hpp>
    #include <memory>

class RT::Client::Scenes::GameScene : public GE::Scene::AScene
{

    private:
        // SpawnManager spawnManager;
        std::string levelPath;
        std::string objectsPath;
        // std::unique_ptr<SpawnManager> spawnManager;
        std::unique_ptr<Transitions::GameStart> gameStartTransition;
        std::unique_ptr<Transitions::GameOver> gameOverTransition;
        std::unique_ptr<Transitions::GameWon> gameWonTransition;
        std::shared_ptr<GE::Network::Client::Client> client = Network::SingletonClient::getInstance();
        bool gameOver;
        bool localOver;
        bool hasWon;
        bool serverHasWon;
        void checkGameOver();
        void checkGameWon();
        void registerSystems();
        void registerComponents();

    public:
        GameScene(GE::Lib::SDL2::Window::Event &event, GE::Lib::SDL2::Graphic::Renderer &renderer, std::string objectsPath, std::string levelPath);
        void setServerHasWon(bool serverHasWon);
        void init();
        void update();
        void render();
};

#endif
