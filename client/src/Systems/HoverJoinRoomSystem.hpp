/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ClickSystemJoinRoom
*/

#ifndef HOVERSYSTEMJOINROOM_HPP_
    #define HOVERSYSTEMJOINROOM_HPP_

    #include "ClientNamespace.hpp"
    #include <GameEngineUtils.hpp>
    #include "ECSNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/JoinRoom.hpp"
    #include <GameEngineECS.hpp>

class RT::Client::Systems::HoverJoinRoomSystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~HoverJoinRoomSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
};

#endif /* !HOVERSYSTEMJoinRoom_HPP_ */
