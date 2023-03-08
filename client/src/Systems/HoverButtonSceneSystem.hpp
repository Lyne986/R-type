/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ClickSystemButtonScene
*/

#ifndef HOVERSYSTEMBUTTONSCENE_HPP_
    #define HOVERSYSTEMBUTTONSCENE_HPP_

    #include "ClientNamespace.hpp"
    #include <GameEngineUtils.hpp>
    #include "ECSNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/ButtonScene.hpp"
    #include <GameEngineECS.hpp>

class RT::Client::Systems::HoverButtonSceneSystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~HoverButtonSceneSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
};

#endif /* !HOVERSYSTEMBUTTONSCENE_HPP_ */
