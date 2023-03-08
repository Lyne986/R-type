#include "ECS/Components/Movable.hpp"

namespace RT::GE::ECS::Components {

    Movable::Movable(Utils::Vector2<float> speed)
    : speed(speed) {}

    Utils::Vector2<float> Movable::getSpeed() const
    {
        return this->speed;
    }

    void Movable::setSpeed(Utils::Vector2<float> speed)
    {
        this->speed = speed;
    }

    void Movable::move(Utils::Vector2<float> &pos, Utils::Vector2<float> &velocity, float deltaTime)
    {
        if (deltaTime > 1) {
            return;
        }
        pos += this->speed * velocity * deltaTime;
    }

    Utils::Vector2<float> Movable::getPredictedPosition(Utils::Vector2<float> pos, Utils::Vector2<float> velocity, float deltaTime)
    {
        if (deltaTime > 1) {
            return pos;
        }
        pos += this->speed * velocity * deltaTime;
        return pos;
    }

}