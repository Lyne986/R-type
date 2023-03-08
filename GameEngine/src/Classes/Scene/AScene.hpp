#ifndef __RT_CLIENT_OBJECT_SCENE_ASCENE_HPP__
    #define __RT_CLIENT_OBJECT_SCENE_ASCENE_HPP__

    #include "SceneNamespace.hpp"
    #include "Scene/IScene.hpp"
    #include "Lib/SDL2/Graphic/Renderer.hpp"
    #include "Lib/SDL2/Graphic/SpriteManager.hpp"
    #include "ECS/ComponentManager.hpp"
    #include "ECS/SystemManager.hpp"
    #include "ECS/EntityManager.hpp"

namespace RT::GE::Scene
{
    class AScene : public IScene
    {
        private:
        bool changeScene = false;
        std::string nextScene = "";

        protected:
            Lib::SDL2::Window::Event &event;
            Lib::SDL2::Graphic::Renderer &renderer;
            Lib::SDL2::Graphic::SpriteManager spriteManager;
            std::shared_ptr<ECS::ComponentManager> componentManager;
            std::shared_ptr<ECS::SystemManager> systemManager;
            std::shared_ptr<ECS::EntityManager> entityManager;

        public:
        AScene(Lib::SDL2::Window::Event &event, Lib::SDL2::Graphic::Renderer &renderer, std::string objectsPath);
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void init() = 0;
        bool getChangeScene() const;
        void setChangeScene(bool enabled);
        std::string getNextScene() const;
        void setNextScene(std::string nextScene);
        std::shared_ptr<ECS::EntityManager> getEntityManager();
    };
};

#endif
