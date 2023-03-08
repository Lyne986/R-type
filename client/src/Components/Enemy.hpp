/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Enemy.hpp
*/

#ifndef __RT_GE_ECS_COMPONENTS_ENEMY_HPP__
    #define __RT_GE_ECS_COMPONENTS_ENEMY_HPP__

    #include "ClientNamespace.hpp"
    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"
    #include <vector>
    #include "Utils/Vector2.hpp"
    #include "Utils/JSON.hpp"

class RT::Client::Components::Enemy
: public RT::GE::ECS::Components::AComponent {

    public:
        Enemy(std::string dataPath);
        ~Enemy() {};

        struct State {
            float time;
            GE::Utils::Vector2<float> velocity;
        };
        GE::Utils::Vector2<float> getCurrentVelocity();
        float getCurrentTime() const;
        void updateState(float deltaTime);
        bool updateShoot(float deltaTime);
        bool getCanShoot() const;
        std::string getBulletPath() const;
        unsigned int getScoreValue() const;

    private:
        std::vector<State> states;
        void addState(nlohmann::json stateData);
        unsigned int currentState;
        float currentTime;
        bool canShoot;
        std::string bulletPath;
        float shootInterval;
        float currentShootInterval;
        unsigned int scoreValue;
};

#endif