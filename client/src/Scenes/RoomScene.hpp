/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** RoomScene
*/

#ifndef ROOMSCENE_HPP_
#define ROOMSCENE_HPP_

    #include "ClientNamespace.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/ButtonScene.hpp"
    #include "Components/CreateRoom.hpp"
    #include "Components/JoinRoom.hpp"
    #include "Components/SelectRoom.hpp"
    #include "Components/UnselectRoom.hpp"
    #include "Systems/ClickButtonSceneSystem.hpp"
    #include "Systems/ReleaseButtonSceneSystem.hpp"
    #include "Systems/HoverCreateRoomSystem.hpp"
    #include "Systems/HoverSelectRoomSystem.hpp"
    #include "Systems/HoverJoinRoomSystem.hpp"
    #include "Systems/HoverUnselectRoomSystem.hpp"
    #include <GameEngineECS.hpp>
    #include <GameEngineScene.hpp>
    #include <GameEngineRendering.hpp>
    #include <GameEngineInput.hpp>
    #include <GameEngineWindow.hpp>
    #include <GameEngineNetwork.hpp>
    #include <memory>
    #include "Network/SingletonClient.hpp"

class RT::Client::Scenes::RoomScene : public GE::Scene::AScene {
    public:
        RoomScene(GE::Lib::SDL2::Window::Event& event, GE::Lib::SDL2::Graphic::Renderer& renderer, std::string objectsPath);
        void registerComponents();
        void update();
        void render();
        void init();
        void display_room();
        void getRooms();
        void setRooms(RT::GE::Network::Message::ListRoom room);
    
    private:
        std::shared_ptr<RT::GE::Network::Client::Client> _client = Network::SingletonClient::getInstance();
        std::vector<RT::GE::Network::Message::ListRoom> _rooms;
        std::vector<bool> _isUpdate;
        std::chrono::system_clock::time_point _time;
};

#endif /* !ROOMSCENE_HPP_ */
