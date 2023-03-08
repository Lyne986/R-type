/*
** EPITECH PROJECT, 2022
** B-CPP-500-MPL-5-1-rtype-hugo.marrasse
** File description:
** Animation.cpp
*/

#include "ECS/Components/Animation.hpp"
#include <iostream>

namespace RT::GE::ECS::Components {

    Animation::Animation(nlohmann::json animationsData)
    {
        for (auto it = animationsData.begin(); it != animationsData.end(); ++it) {
            if (this->animations.empty()) {
                this->currentAnim = it.value()["name"];
            }
            this->addAnim(it.value());
        }
        this->currentIndex.x = this->animations[this->currentAnim].startIndex;
        this->currentIndex.y = this->animations[this->currentAnim].startIndexY;
        this->currentTime = 0;
        this->done = false;
    }

    void Animation::addAnim(nlohmann::json animData)
    {
        Anim anim;

        anim.loop = animData["loop"];
        anim.startIndex = animData["startIndex"];
        anim.endIndex = animData["endIndex"];
        anim.speed = animData["speed"];
        if (animData["startY"] != nullptr) {
            anim.startIndexY = animData["startY"];
            std::cout << "startY " << anim.startIndexY << std::endl;
        } else {
            anim.startIndexY = 0;
        }
        if (!anim.loop) {
            anim.nextAnim = animData["nextAnim"];
        } else {
            anim.nextAnim = "";
        }
        if (animData["destroyAfterPlaying"] != nullptr) {
            anim.destroyAfterPlaying = animData["destroyAfterPlaying"];
        } else {
            anim.destroyAfterPlaying = false;
        }
        this->animations[animData["name"]] = anim;
    }

    Utils::Vector2<int> Animation::getCurrentIndex() const
    {
        return this->currentIndex;
    }

    void Animation::updateIndex(float deltaTime)
    {
        Anim current = this->animations[this->currentAnim];

        this->currentTime += deltaTime;
        if (this->currentTime >= current.speed) {
            this->currentTime = 0;
            this->currentIndex.x++;
            if (this->currentIndex.x > current.endIndex) {
                if (current.destroyAfterPlaying) {
                    this->done = true;
                } else if (current.loop) {
                    this->currentIndex.x = current.startIndex;
                    this->currentIndex.y = current.startIndexY;
                } else {
                    this->setCurrentAnim(current.nextAnim);
                }
            }
        }
    }

    void Animation::setCurrentAnim(std::string name)
    {
        this->currentAnim = name;
        this->currentTime = 0;
        this->currentIndex.x = this->animations[this->currentAnim].startIndex;
    }

    bool Animation::hasAnim(std::string name)
    {
        if (this->animations.find(name) != this->animations.end()) {
            return true;
        }
        return false;
    }

    bool Animation::getDone() const
    {
        return this->done;
    }
}
