cmake_minimum_required(VERSION 3.11)

# set the project name
project(r-type_server)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} cmake)

set(SRC
    src/main.cpp
    src/GameLogic/Party.cpp
    src/GameLogic/PartyManager.cpp
    src/GameLogic/Game.cpp
    src/GameLogic/SpawnManager.cpp
    src/Network/MyServer.cpp
    src/Network/Message/Parser/JoinMessage.cpp
    src/Network/Message/Parser/PlayerPosition.cpp
    src/Network/Message/Parser/AParser.cpp
    src/Network/Message/Parser/Parser.cpp
    src/Network/Message/Parser/ShootPos.cpp
    src/Network/Message/Parser/Shoot.cpp
    src/Network/Message/Parser/PlayerDisconnect.cpp
    src/Network/Message/Parser/CreateRoom.cpp
    src/Network/Message/Parser/JoinRoom.cpp
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
    Network
    GameEngine
)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION .)
