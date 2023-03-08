/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** CHANGESOUNDSystem
*/

#ifndef CHANGESOUNDSystem_HPP_
    #define CHANGESOUNDSystem_HPP_

    #include "ClientNamespace.hpp"
    #include <GameEngineUtils.hpp>
    #include <GameEngineECS.hpp>
    #include "ECSNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/ButtonSound.hpp"

class RT::Client::Systems::ChangeSoundSystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~ChangeSoundSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
};

#endif /* !CHANGESOUNDSystem_HPP_ */
