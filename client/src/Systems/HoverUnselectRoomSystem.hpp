/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ClickSystemUnselectRoom
*/

#ifndef HOVERSYSTEMSUNELECTROOM_HPP_
    #define HOVERSYSTEMUNSELECTROOM_HPP_

    #include "ClientNamespace.hpp"
    #include <GameEngineUtils.hpp>
    #include "ECSNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/UnselectRoom.hpp"
    #include <GameEngineECS.hpp>

class RT::Client::Systems::HoverUnselectRoomSystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~HoverUnselectRoomSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
};

#endif /* !HOVERSYSTEMUnselectRoom_HPP_ */
