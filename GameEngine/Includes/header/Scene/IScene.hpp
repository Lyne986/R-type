#ifndef __RT_CLIENT_OBJECT_SCENE_ISCENE_HPP__
    #define __RT_CLIENT_OBJECT_SCENE_ISCENE_HPP__

    #include "SceneNamespace.hpp"
    #include <string>

namespace RT::GE::Scene
{
    class IScene
    {
        public:
        virtual void update() = 0;
        virtual void render() = 0;
        virtual void init() = 0;
    };
};

#endif