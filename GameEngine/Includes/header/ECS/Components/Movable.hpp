#ifndef __RT_GE_ECS_COMPONENTS_MOVABLE_HPP__
    #define __RT_GE_ECS_COMPONENTS_MOVABLE_HPP__

    #include "ECSNamespace.hpp"
    #include "ECS/Components/AComponent.hpp"
    #include "Utils/Vector2.hpp"

class RT::GE::ECS::Components::Movable
 : public RT::GE::ECS::Components::AComponent {

    private:
    Utils::Vector2<float> speed;

    public:
    Movable(Utils::Vector2<float> speed = Utils::Vector2<float>(0, 0));
    ~Movable() {};

    Utils::Vector2<float> getSpeed() const;
    void setSpeed(Utils::Vector2<float> speed);
    void move(Utils::Vector2<float> &pos, Utils::Vector2<float> &velocity, float deltaTime);
    Utils::Vector2<float> getPredictedPosition(Utils::Vector2<float> pos, Utils::Vector2<float> velocity, float deltaTime);
};

#endif