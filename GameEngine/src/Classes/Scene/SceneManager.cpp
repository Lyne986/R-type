#include "Scene/SceneManager.hpp"

namespace RT::GE::Scene {

    SceneManager::SceneManager(GE::Lib::SDL2::Graphic::Renderer &renderer)
    : renderer(renderer)
    {
    }

    void SceneManager::registerScene(std::string name, std::shared_ptr<AScene> scene)
    {
        this->scenes[name] = scene;
        if (this->currentScene == "") {
            this->currentScene = name;
        }
    }

    void SceneManager::init()
    {
        this->scenes[this->currentScene]->init();
    }

    void SceneManager::update()
    {
        if (this->scenes[this->currentScene]->getChangeScene()) {
            this->scenes[this->currentScene]->setChangeScene(false);
            this->currentScene = this->scenes[this->currentScene]->getNextScene();
            this->scenes[this->currentScene]->init();
        }
        this->scenes[this->currentScene]->update();
    }

    void SceneManager::render()
    {
        this->scenes[this->currentScene]->render();
    }

    void SceneManager::setCurrentScene(std::string name)
    {
        this->currentScene = name;
    }

    std::shared_ptr<AScene> SceneManager::getCurr()
    {
        if (this->scenes.find(this->currentScene) != this->scenes.end()) {
            return this->scenes[this->currentScene];
        } else {
            return nullptr;
        }
    }

}