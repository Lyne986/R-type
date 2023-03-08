/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** ClickSystemButtonScene
*/

#ifndef CLICKSYSTEMBUTTONSCENE_HPP_
    #define CLICKSYSTEMBUTTONSCENE_HPP_

    #include "ClientNamespace.hpp"
    #include <GameEngineUtils.hpp>
    #include "ECSNamespace.hpp"
    #include "Utils/Debug/Log.hpp"
    #include "Utils/Vector2.hpp"
    #include "Components/ButtonScene.hpp"

class RT::Client::Systems::ClickButtonSceneSystem
 : public RT::GE::ECS::Systems::ASystem {

    public:
        ~ClickButtonSceneSystem() {};
        void init(std::shared_ptr<GE::ECS::EntityManager> entityManager);
        void update(std::shared_ptr<GE::ECS::EntityManager> entityManager);
};

#endif /* !CLICKSYSTEMBUTTONSCENE_HPP_ */
