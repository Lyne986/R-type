/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ClickSystemCreateRoom
*/

#ifndef HOVERSYSTEMCREATEROOM_HPP_
    #define HOVERSYSTEMCREATEROOM_HPP_

    #include "ClientNamespace.hpp"
    #include <GameEngineUtils.hpp>
    #include "ECSNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/CreateRoom.hpp"
    #include <GameEngineECS.hpp>

class RT::Client::Systems::HoverCreateRoomSystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~HoverCreateRoomSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
};

#endif /* !HOVERSYSTEMCreateRoom_HPP_ */
