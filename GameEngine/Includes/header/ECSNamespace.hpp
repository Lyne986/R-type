#ifndef __RT_GAMEENGINE_ECSNAMESPACE_HPP__
    #define __RT_GAMEENGINE_ECSNAMESPACE_HPP__

namespace RT::GE::ECS {
    class Entity;
    class EntityManager;
    class SystemManager;
    class ComponentManager;
    class AudioManager;
    namespace Components {
        class AComponent;
        class ADrawable;
        class Text;
        class SpriteSheet;
        class Parallax;
        class Position;
        class Velocity;
        class Movable;
        class Input;
        class Collider;
        class Animation;
    };
    namespace Systems {
        class ASystem;
        class ParallaxSystem;
        class RenderSystem;
        class MovementSystem;
        class CollisionSystem;
        class AnimationSystem;
    };
};

#endif