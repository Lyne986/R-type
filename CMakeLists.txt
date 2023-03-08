cmake_minimum_required(VERSION 3.11)

# set the project name
project(r-type)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} cmake)

set(SDL2_DIR cmake)
set(SDL2_image_DIR cmake)
set(SDL2_TTF_DIR cmake)
set(SDL2_mixer_DIR cmake)
set(nlohmann_json_DIR cmake)
set(asio_DIR cmake)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_TTF REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(asio REQUIRED)

if (WIN32)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_FLAGS "/std:c++17")
    link_libraries(${SDL2_BINARY_DIR}/Debug/SDL2d.lib ${SDL2_image_BINARY_DIR}/Debug/SDL2_imaged.lib ${SDL2_ttf_BINARY_DIR}/Debug/SDL2_ttfd.lib ${SDL2_mixer_BINARY_DIR}/Debug/SDL2_mixerd.lib ${asio_SOURCE_DIR}/asio/include)
ELSE()
    set(CMAKE_CXX_FLAGS "-lstdc++fs -std=c++17")
    link_libraries(${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES} ${SDL2_mixer_LIBRAIRIES} ${nlohmann_json_LIBRARIES} ${asio_SOURCE_DIR}/asio/include)
ENDIF()

include_directories(${SDL2_SOURCE_DIR}/include ${SDL2_image_SOURCE_DIR} ${SDL2_ttf_SOURCE_DIR} ${SDL2_mixer_SOURCE_DIR}/include ${nlohmann_json_SOURCE_DIR}/include ${asio_SOURCE_DIR}/asio/include)
include_directories("GameEngine/Includes/header" "GameEngine/Includes" "GameEngine/src/Classes")

add_subdirectory(GameEngine)
add_subdirectory(client)
add_subdirectory(server)
