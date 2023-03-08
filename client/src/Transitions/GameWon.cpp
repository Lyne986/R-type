/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** GameWon.cpp
*/

#include "Transitions/GameWon.hpp"

namespace RT::Client::Transitions
{

    void GameWon::init(std::shared_ptr<GE::ECS::EntityManager> entityManager)
    {
        GE::ECS::ComponentManager &componentManager = entityManager->getComponentManager();
        GE::ECS::Entity textEntity = entityManager->createEntity("assets/objects/transitions/gameWonText.json");
        std::shared_ptr<GE::ECS::Components::ADrawable> cDrawable = componentManager.getComponent<GE::ECS::Components::ADrawable>(textEntity);

        this->cText = std::dynamic_pointer_cast<GE::ECS::Components::Text>(cDrawable);
        this->currentLength = 0;
        this->currentState = FADE_IN;
        this->alpha = 0;
        this->isPlaying = true;
    }

    void GameWon::update(std::shared_ptr<GE::ECS::EntityManager>)
    {
        static GE::Lib::SDL2::Timer timer;
        timer.tick();
        float deltaTime = timer.getElapsedSeconds();

        if (!this->isPlaying || deltaTime > 1) {
            return;
        }
        this->currentLength += deltaTime;

        float currentAlpha = 0;
        if (this->currentState == FADE_IN) {
            currentAlpha = this->lerp(1, 255, this->currentLength);
            if (this->currentLength >= 1) {
                this->currentLength = 0;
                currentAlpha = 255;
                this->currentState = FADE_OUT;
            }
        } else if (this->currentState == FADE_OUT) {
            currentAlpha = this->lerp(255, 1, this->currentLength);
            if (this->currentLength >= 1) {
                this->currentLength = 0;
                this->isPlaying = false;
                this->currentState = END;
                currentAlpha = 1;
            }
        }
        this->cText->getText().setColorAlpha(currentAlpha);
    }
}