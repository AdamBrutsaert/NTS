/*
** EPITECH PROJECT, 2024
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include "nts/components/ComponentFactory.hpp"

#include "nts/components/special/OutputComponent.hpp"
#include "nts/components/special/InputComponent.hpp"
#include "nts/components/special/TrueComponent.hpp"
#include "nts/components/special/FalseComponent.hpp"
#include "nts/components/special/ClockComponent.hpp"

namespace nts {
    std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> ComponentFactory::_components{
        {"output", []() { return std::make_unique<OutputComponent>(); }},
        {"input", []() { return std::make_unique<InputComponent>(); }},
        {"true", []() { return std::make_unique<TrueComponent>(); }},
        {"false", []() { return std::make_unique<FalseComponent>(); }},
        {"clock", []() { return std::make_unique<ClockComponent>(); }},
    };

    std::unique_ptr<nts::IComponent> ComponentFactory::createComponent(const std::string& type)
    {
        auto it = ComponentFactory::_components.find(type);
        if (it == ComponentFactory::_components.end())
            throw InvalidComponentType();
        return it->second();
    }
}
