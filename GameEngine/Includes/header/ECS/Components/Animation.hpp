/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Animation.hpp
*/

#ifndef __RT_GAMEENGINE_ECS_COMPONENTS_ANIMATION_HPP__
    #define __RT_GAMEENGINE_ECS_COMPONENTS_ANIMATION_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"

    #include "Utils/JSON.hpp"
    #include "Utils/Vector2.hpp"

    #include <string>
    #include <unordered_map>

class RT::GE::ECS::Components::Animation
: public RT::GE::ECS::Components::AComponent {

    private:
        struct Anim {
            bool loop;
            float speed;
            unsigned int startIndex;
            unsigned int startIndexY;
            unsigned int endIndex;
            bool destroyAfterPlaying;
            std::string nextAnim;
        };
        std::unordered_map<std::string, Anim> animations;
        std::string currentAnim;
        Utils::Vector2<int> currentIndex;
        float currentTime;
        bool done;
        void addAnim(nlohmann::json animationData);

    public:
        Animation(nlohmann::json animationsData);
        ~Animation(){};
        void updateIndex(float deltaTime);
        Utils::Vector2<int> getCurrentIndex() const;
        void setCurrentAnim(std::string name);
        bool hasAnim(std::string name);
        bool getDone() const;
};

#endif
