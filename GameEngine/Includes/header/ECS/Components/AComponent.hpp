#ifndef __RT_GE_ECS_COMPONENTS_ACOMPONENT_HPP__
    #define __RT_GE_ECS_COMPONENTS_ACOMPONENT_HPP__

    #include "ECSNamespace.hpp"
    #include <memory>
    #include <string>

class RT::GE::ECS::Components::AComponent {

    private:
    std::string name = "";

    public:
    AComponent(std::string name = "");
    std::string getName() const;
    virtual ~AComponent() = default;

};

#endif