/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Core.cpp
*/

#include "Core.hpp"

namespace RT::Client
{
    Core::Core()
        : window("RType", 50, 50, 960, 540), renderer(window, -1, SDL_RENDERER_ACCELERATED)
    {
        this->sceneManager = std::make_shared<RT::GE::Scene::SceneManager>(this->renderer);
        this->parser = Network::Message::Parser::Parser::getInstance(this->sceneManager);
        this->sceneManager->registerScene <RT::Client::Scenes::MenuScene>("menu", event, "assets/objects/menu/");
        this->sceneManager->registerScene<RT::Client::Scenes::OptionScene>("option", event, "assets/objects/option/");
        this->sceneManager->registerScene<RT::Client::Scenes::RoomScene>("room", event, "assets/objects/room/");

        std::shared_ptr<Scenes::GameScene> gameScene = std::make_shared<Scenes::GameScene>(this->event, this->renderer, "assets/objects/game/", "assets/objects/data/level1.json");
        this->sceneManager->registerScene("game", gameScene);
        this->sceneManager->setCurrentScene("menu");
    }

    void Core::init()
    {
        this->sceneManager->init();
        this->client->connect("127.0.0.1", 60000);
    }

    void Core::networkUpdate()
    {
        if (!this->client->isConnected())
            return;
        if (!this->client->incoming().isEmpty())
        {
            this->parser->parseMessage(this->client, this->client->incoming().pop_front().msg);
        }
        if (!this->client->incomingUdp().isEmpty()) {
            this->parser->parseMessage(this->client, this->client->incomingUdp().pop_front().msg);
        }
    }

    void Core::run()
    {
        float accumulatedSeconds = 0;
        RT::GE::Lib::SDL2::Timer systemTimer;
        while (!this->event.isQuit())
        {
            this->networkUpdate();
            this->event.poll();
            systemTimer.tick();
            accumulatedSeconds += systemTimer.getElapsedSeconds();
            if (this->event.isKeyReleased(SDL_SCANCODE_X))
                this->client->pingServer();
            if (std::isgreater(accumulatedSeconds, CYCLE_TIME))
            {
                accumulatedSeconds = -CYCLE_TIME;
                this->sceneManager->update();
                this->event.clear();
            }
            this->sceneManager->render();
        }
    }

}
