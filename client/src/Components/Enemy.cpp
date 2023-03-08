/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Enemy.cpp
*/

#include "Enemy.hpp"

namespace RT::Client::Components {
    Enemy::Enemy(std::string dataPath): AComponent("enemy")
    {
        RT::GE::Utils::JSON json(dataPath);
        nlohmann::json data = json.getData();

        for (auto it = data["states"].begin(); it != data["states"].end(); ++it)
        {
            this->addState(it.value());
        }
        this->currentState = 0;
        if (data["shoot"] != nullptr) {
            this->canShoot = true;
            this->shootInterval = data["shoot"]["shootInterval"];
            this->currentShootInterval = this->shootInterval;
            this->bulletPath = data["shoot"]["bulletPath"];
        } else {
            this->canShoot = false;
        }
        this->scoreValue = data["score"];
        this->currentTime = this->states[this->currentState].time;
    }

    void Enemy::addState(nlohmann::json stateData)
    {
        State state;

        state.time = stateData["time"];
        state.velocity = GE::Utils::Vector2<float>(stateData["velocity"]["x"], stateData["velocity"]["y"]);
        this->states.push_back(state);
    }

    GE::Utils::Vector2<float> Enemy::getCurrentVelocity()
    {
        return this->states[this->currentState].velocity;
    }

    float Enemy::getCurrentTime() const
    {
        return this->currentTime;
    }

    unsigned int Enemy::getScoreValue() const
    {
        return this->scoreValue;
    }

    void Enemy::updateState(float deltaTime)
    {
        this->currentTime -= deltaTime;
        if (this->currentTime <= 0) {
            if (this->currentState < this->states.size() - 1) {
                this->currentState++;
            } else {
                this->currentState = 0;
            }
            this->currentTime = this->states[this->currentState].time;
        }
    }

    bool Enemy::updateShoot(float deltaTime)
    {
        this->currentShootInterval -= deltaTime;
        if (this->currentShootInterval <= 0) {
            this->currentShootInterval = this->shootInterval;
            return true;
        }
        return false;
    }

    bool Enemy::getCanShoot() const
    {
        return this->canShoot;
    }

    std::string Enemy::getBulletPath() const
    {
        return this->bulletPath;
    }

}