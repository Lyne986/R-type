/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ClickSystemSelectRoom
*/

#ifndef HOVERSYSTEMSELECTROOM_HPP_
    #define HOVERSYSTEMSELECTROOM_HPP_

    #include "ClientNamespace.hpp"
    #include <GameEngineUtils.hpp>
    #include "ECSNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/SelectRoom.hpp"
    #include <GameEngineECS.hpp>
    #include "Components/SingletonIdRoom.hpp"

class RT::Client::Systems::HoverSelectRoomSystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~HoverSelectRoomSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);

    private:
        std::shared_ptr<SingletonIdRoom> _IdInstance = SingletonIdRoom::getInstance();
};

#endif /* !HOVERSYSTEMSelectRoom_HPP_ */
