cmake_minimum_required(VERSION 3.11)

# set the project name
project(r-type_client)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} cmake)

set(SRC
    src/main.cpp
    src/Core.cpp

    src/Transitions/ATransition.cpp
    src/Transitions/GameStart.cpp
    src/Transitions/GameOver.cpp
    src/Transitions/GameWon.cpp

    src/Components/OnlinePlayer.cpp
    src/Components/MainPlayer.cpp
    src/Components/ButtonScene.cpp
    src/Components/Health.cpp
    src/Components/HealthUI.cpp
    src/Components/Damage.cpp
    src/Components/Enemy.cpp
    src/Components/ChangeKey.cpp
    src/Components/Score.cpp
    src/Components/ButtonSound.cpp
    src/Components/CreateRoom.cpp
    src/Components/JoinRoom.cpp
    src/Components/SelectRoom.cpp
    src/Components/UnselectRoom.cpp
    src/Components/SingletonIdRoom.cpp

    src/Systems/OnlinePlayer.cpp
    src/Systems/MainPlayer.cpp
    src/Systems/InputSystem.cpp
    src/Systems/HealthSystem.cpp
    src/Systems/EnemySystem.cpp
    src/Systems/ChangeKeySystem.cpp
    src/Systems/ScoreSystem.cpp
    src/Systems/ChangeSoundSystem.cpp
    src/Systems/ClickButtonSceneSystem.cpp
    src/Systems/HoverButtonSceneSystem.cpp
    src/Systems/ReleaseButtonSceneSystem.cpp
    src/Systems/HoverCreateRoomSystem.cpp
    src/Systems/HoverSelectRoomSystem.cpp
    src/Systems/HoverJoinRoomSystem.cpp
    src/Systems/HoverUnselectRoomSystem.cpp


    src/Scenes/GameScene.cpp
    src/Scenes/MenuScene.cpp
    src/Scenes/OptionScene.cpp
    src/Scenes/RoomScene.cpp

    src/Network/SingletonClient.cpp
    src/Network/Message/Parser/Parser.cpp
    src/Network/Message/Parser/AParser.cpp
    src/Network/Message/Parser/JoinMessage.cpp
    src/Network/Message/Parser/PlayerJoin.cpp
    src/Network/Message/Parser/SpawnEnemy.cpp
    src/Network/Message/Parser/PlayerPosition.cpp
    src/Network/Message/Parser/ShootPos.cpp
    src/Network/Message/Parser/PlayerWin.cpp
    src/Network/Message/Parser/Shoot.cpp
    src/Network/Message/Parser/UDPInit.cpp
    src/Network/Message/Parser/PlayerDisconnect.cpp
    src/Network/Message/Parser/ListRoom.cpp
)

include_directories("src/")

IF(WIN32)
ELSE()
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -W -Wall -Wextra")
ENDIF()

add_executable(${PROJECT_NAME} ${SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

target_link_libraries(${PROJECT_NAME} PRIVATE
    asio::asio
    SDL2
    SDL2::image
    SDL2::ttf
    SDL2::mixer
    GameEngine
    Network
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .)
