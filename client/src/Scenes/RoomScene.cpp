/*
** EPITECH PROJECT, 2022
** rtype
** File description:
** RoomScene
*/

#include "RoomScene.hpp"

namespace RT::Client::Scenes {

    RoomScene::RoomScene(GE::Lib::SDL2::Window::Event& event, GE::Lib::SDL2::Graphic::Renderer& renderer, std::string objectsPath)
        : AScene(event, renderer, objectsPath)
    {
        this->registerComponents();
        this->entityManager->init();

        RT::GE::ECS::Entity buttonNew = this->entityManager->getEntity("add");
        RT::GE::ECS::Entity buttonJoin = this->entityManager->getEntity("join");
        RT::GE::ECS::Entity buttonCancel = this->entityManager->getEntity("cancel");

        std::shared_ptr<RT::Client::Components::CreateRoom> clickNew = std::make_shared<RT::Client::Components::CreateRoom>("Default", event);
        std::shared_ptr<RT::Client::Components::JoinRoom> clickJoin = std::make_shared<RT::Client::Components::JoinRoom>("Default", event, "game", this);
        std::shared_ptr<RT::Client::Components::UnselectRoom> clickCancel = std::make_shared<RT::Client::Components::UnselectRoom>("Default", event);

        this->componentManager->addComponent<Components::CreateRoom>(buttonNew, clickNew);
        this->componentManager->addComponent<Components::JoinRoom>(buttonJoin, clickJoin);
        this->componentManager->addComponent<Components::UnselectRoom>(buttonCancel, clickCancel);

        this->systemManager->addRenderSystem<RT::GE::ECS::Systems::RenderSystem>();
    }

    void RoomScene::getRooms()
    {
        if (_time + std::chrono::seconds(1) >= std::chrono::system_clock::now())
            return;
        _time = std::chrono::system_clock::now();
        GE::Network::Message::ListRoom listRoom;
        message_s<CustomMsgTypes> msg("ListRoom");
        msg.header.id = CustomMsgTypes::RoomList;

        msg << listRoom;

        _client->send(msg);
        display_room();
    }

    void RoomScene::display_room()
    {
        int i = 0;

        for (auto &it : _rooms) {
            RT::GE::ECS::Entity test = this->entityManager->createEntity("assets/objects/prefabs/room.json");
            std::shared_ptr<GE::ECS::Components::Position> testPosition = this->componentManager->getComponent<GE::ECS::Components::Position>(test);
            testPosition->set(GE::Utils::Vector2<float>(testPosition->get().x, testPosition->get().x + (i * 100)));
            std::shared_ptr<RT::GE::ECS::Components::Text> testText = this->componentManager->getComponent<GE::ECS::Components::Text>(test);
            
            RT::GE::ECS::Entity roomName = this->entityManager->createEntity("assets/objects/prefabs/room_name_text.json");
            std::shared_ptr<RT::GE::ECS::Components::ADrawable> cDrawable = this->componentManager->getComponent<RT::GE::ECS::Components::ADrawable>(roomName);
            std::shared_ptr<RT::GE::ECS::Components::Text> roomNameText = std::dynamic_pointer_cast<GE::ECS::Components::Text>(cDrawable);
            roomNameText->setText("Name : " + (std::string (it.name)));

            std::shared_ptr<GE::ECS::Components::Position> roomNamePosition = this->componentManager->getComponent<GE::ECS::Components::Position>(roomName);
            roomNamePosition->set(GE::Utils::Vector2<float>(roomNamePosition->get().x, roomNamePosition->get().y + (i * 100)));

            RT::GE::ECS::Entity roomNbr = this->entityManager->createEntity("assets/objects/prefabs/room_player_text.json");
            std::shared_ptr<RT::GE::ECS::Components::ADrawable> cDrawable2 = this->componentManager->getComponent<RT::GE::ECS::Components::ADrawable>(roomNbr);
            std::shared_ptr<RT::GE::ECS::Components::Text> roomNbrText = std::dynamic_pointer_cast<GE::ECS::Components::Text>(cDrawable2);
            roomNbrText->setText(std::to_string(it.nbPlayer) + " / 4");

            std::shared_ptr<GE::ECS::Components::Position> roomNbrPosition = this->componentManager->getComponent<GE::ECS::Components::Position>(roomNbr);
            roomNbrPosition->set(GE::Utils::Vector2<float>(roomNbrPosition->get().x, roomNbrPosition->get().y + (i * 100)));

            this->componentManager->addComponent<Components::SelectRoom>(test, std::make_shared<RT::Client::Components::SelectRoom>(it.id, this->event));
            i++;
        }
    }

    void RoomScene::registerComponents()
    {
        this->systemManager->addLogicSystem<RT::Client::Systems::HoverCreateRoomSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::HoverSelectRoomSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::HoverJoinRoomSystem>();
        this->systemManager->addLogicSystem<RT::Client::Systems::HoverUnselectRoomSystem>();
    }

    void RoomScene::init()
    {
        systemManager->init(this->entityManager);
    }

    void RoomScene::update()
    {
        getRooms();
        systemManager->updateLogic(this->entityManager);
    }

    void RoomScene::render()
    {
        renderer.clear(0, 0, 0, 255);
        systemManager->updateRender(this->entityManager);
        renderer.render();
    }

    void RoomScene::setRooms(RT::GE::Network::Message::ListRoom room)
    {
        std::vector<RT::GE::Network::Message::ListRoom>::iterator it = std::find_if(_rooms.begin(), _rooms.end(), [&room](RT::GE::Network::Message::ListRoom &it) {
            return it.id == room.id;
        });
        if (it != _rooms.end()) {
            int index = it - _rooms.begin();
            _isUpdate[index] = true;
            return;
        }
        _rooms.push_back(room);
        _isUpdate.push_back(true);
        if (room.count == room.nbrRooms) {
            for (int i : _isUpdate) {
                if (i == false) {
                    _rooms.erase(_rooms.begin() + i - 1);
                    _isUpdate.erase(_isUpdate.begin() + i - 1);
                }   
            }
        }
    }

}