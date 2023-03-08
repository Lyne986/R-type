#ifndef __OBJECT_SCENE_MANAGER_HPP__
    #define __OBJECT_SCENE_MANAGER_HPP__

    #include "SceneNamespace.hpp"
    #include "Scene/AScene.hpp"
    #include "Lib/SDL2/Graphic/Renderer.hpp"
    #include <memory>
    #include <unordered_map>

namespace RT::GE::Scene
{
    class SceneManager
    {
        private:
        std::unordered_map<std::string, std::shared_ptr<AScene>> scenes;
        std::string currentScene = "";
        GE::Lib::SDL2::Graphic::Renderer &renderer;

        public:
        SceneManager(GE::Lib::SDL2::Graphic::Renderer &renderer);
        template<typename T>
        void registerScene(std::string name, Lib::SDL2::Window::Event &event, std::string objectsPath) {
            this->scenes[name] = std::make_shared<T>(event, renderer, objectsPath);
            if (this->currentScene == "") {
                this->currentScene = name;
            }
        }
        void registerScene(std::string name, std::shared_ptr<AScene> scene);
        void init();
        void update();
        void render();
        void setCurrentScene(std::string name);
        std::shared_ptr<AScene> getCurr();
    };
}

#endif