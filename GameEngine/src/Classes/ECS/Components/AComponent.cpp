#include "ECS/Components/AComponent.hpp"

namespace RT::GE::ECS::Components {

    AComponent::AComponent(std::string name) {
        this->name = name;
    }

    std::string AComponent::getName() const {
        return (this->name);
    }

}