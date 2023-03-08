/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** CHANGEKEYSYSTEM
*/

#ifndef CHANGEKEYSYSTEM_HPP_
    #define CHANGEKEYSYSTEM_HPP_

    #include "ClientNamespace.hpp"
    #include <GameEngineUtils.hpp>
    #include "ECSNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/ChangeKey.hpp"

class RT::Client::Systems::ChangeKeySystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~ChangeKeySystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
};

#endif /* !CHANGEKEYSYSTEM_HPP_ */
