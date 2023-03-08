cmake_minimum_required(VERSION 3.11)

# set the project name
project(r-type_game-engine)

include_directories("src/Classes")

add_library(GameEngine SHARED

    src/Classes/Lib/SDL2/SDL2.cpp
    src/Classes/Lib/SDL2/Timer.cpp

    src/Classes/Lib/SDL2/Audio/Mixer.cpp
    src/Classes/Lib/SDL2/Audio/Music.cpp
    src/Classes/Lib/SDL2/Audio/Sound.cpp

    src/Classes/Lib/SDL2/Graphic/Renderer.cpp
    src/Classes/Lib/SDL2/Graphic/Image.cpp
    src/Classes/Lib/SDL2/Graphic/SpriteManager.cpp
    src/Classes/Lib/SDL2/Graphic/SpriteSheet.cpp
    src/Classes/Lib/SDL2/Graphic/Surface.cpp
    src/Classes/Lib/SDL2/Graphic/Text.cpp
    src/Classes/Lib/SDL2/Graphic/Texture.cpp
    src/Classes/Lib/SDL2/Graphic/Rect.cpp

    src/Classes/Lib/SDL2/Window/Window.cpp
    src/Classes/Lib/SDL2/Window/Event.cpp

    src/Classes/Utils/JSON.cpp
    src/Classes/Utils/Error.cpp
    src/Classes/Utils/Debug/Log.cpp

    src/Classes/Scene/AScene.cpp
    src/Classes/Scene/SceneManager.cpp

    src/Classes/ECS/AudioManager.cpp
    src/Classes/ECS/Entity.cpp
    src/Classes/ECS/EntityManager.cpp
    src/Classes/ECS/ComponentManager.cpp
    src/Classes/ECS/SystemManager.cpp

    src/Classes/ECS/Systems/ASystem.cpp
    src/Classes/ECS/Systems/RenderSystem.cpp
    src/Classes/ECS/Systems/ParallaxSystem.cpp
    src/Classes/ECS/Systems/MovementSystem.cpp
    src/Classes/ECS/Systems/CollisionSystem.cpp
    src/Classes/ECS/Systems/AnimationSystem.cpp

    src/Classes/ECS/Components/AComponent.cpp
    src/Classes/ECS/Components/Position.cpp
    src/Classes/ECS/Components/Velocity.cpp
    src/Classes/ECS/Components/Movable.cpp
    src/Classes/ECS/Components/Input.cpp
    src/Classes/ECS/Components/ADrawable.cpp
    src/Classes/ECS/Components/Text.cpp
    src/Classes/ECS/Components/SpriteSheet.cpp
    src/Classes/ECS/Components/Parallax.cpp
    src/Classes/ECS/Components/Collider.cpp
    src/Classes/ECS/Components/Animation.cpp
)

add_library(Network SHARED
    src/Classes/Network/Client.cpp
    src/Classes/Utils/Debug/Log.cpp
)
