#ifndef __RT_GE_INCLUDES_GAME_ENGINE_ECS_HPP__
    #define __RT_GE_INCLUDES_GAME_ENGINE_ECS_HPP__

    #include "ECS/ComponentManager.hpp"
    #include "ECS/SystemManager.hpp"
    #include "ECS/EntityManager.hpp"
    #include "ECS/AudioManager.hpp"
    #include "ECS/Entity.hpp"

    #include "ECS/Components/AComponent.hpp"
    #include "ECS/Components/SpriteSheet.hpp"
    #include "ECS/Components/Parallax.hpp"
    #include "ECS/Components/Movable.hpp"
    #include "ECS/Components/Position.hpp"
    #include "ECS/Components/Velocity.hpp"
    #include "ECS/Components/Input.hpp"
    #include "ECS/Components/Animation.hpp"

    #include "ECS/Systems/ASystem.hpp"
    #include "ECS/Systems/MovementSystem.hpp"
    #include "ECS/Systems/RenderSystem.hpp"
    #include "ECS/Systems/ParallaxSystem.hpp"
    #include "ECS/Systems/CollisionSystem.hpp"
    #include "ECS/Systems/AnimationSystem.hpp"

#endif