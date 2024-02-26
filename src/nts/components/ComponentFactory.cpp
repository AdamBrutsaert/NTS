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

#include "nts/components/elementary/NotComponent.hpp"
#include "nts/components/elementary/AndComponent.hpp"
#include "nts/components/elementary/OrComponent.hpp"
#include "nts/components/elementary/XorComponent.hpp"
#include "nts/components/elementary/NandComponent.hpp"
#include "nts/components/elementary/NorComponent.hpp"

#include "nts/components/gates/C4001Component.hpp"
#include "nts/components/gates/C4011Component.hpp"
#include "nts/components/gates/C4030Component.hpp"
#include "nts/components/gates/C4069Component.hpp"
#include "nts/components/gates/C4071Component.hpp"
#include "nts/components/gates/C4081Component.hpp"

#include "nts/components/advanced/FullAdderComponent.hpp"
#include "nts/components/advanced/C4008Component.hpp"
#include "nts/components/advanced/LoggerComponent.hpp"

namespace nts {
    std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> ComponentFactory::_components{
        {"output", []() { return std::make_unique<OutputComponent>(); }},
        {"input", []() { return std::make_unique<InputComponent>(); }},
        {"true", []() { return std::make_unique<TrueComponent>(); }},
        {"false", []() { return std::make_unique<FalseComponent>(); }},
        {"clock", []() { return std::make_unique<ClockComponent>(); }},

        {"not", []() { return std::make_unique<NotComponent>(); }},
        {"and", []() { return std::make_unique<AndComponent>(); }},
        {"or", []() { return std::make_unique<OrComponent>(); }},
        {"xor", []() { return std::make_unique<XorComponent>(); }},
        {"nand", []() { return std::make_unique<NandComponent>(); }},
        {"nor", []() { return std::make_unique<NorComponent>(); }},

        {"4001", []() { return std::make_unique<C4001Component>(); }},
        {"4011", []() { return std::make_unique<C4011Component>(); }},
        {"4030", []() { return std::make_unique<C4030Component>(); }},
        {"4069", []() { return std::make_unique<C4069Component>(); }},
        {"4071", []() { return std::make_unique<C4071Component>(); }},
        {"4081", []() { return std::make_unique<C4081Component>(); }},

        {"full_adder", []() { return std::make_unique<FullAdderComponent>(); }},
        {"4008", []() { return std::make_unique<C4008Component>(); }},
        {"logger", []() { return std::make_unique<LoggerComponent>(); }},
    };

    std::unique_ptr<nts::IComponent> ComponentFactory::createComponent(const std::string& type)
    {
        auto it = ComponentFactory::_components.find(type);
        if (it == ComponentFactory::_components.end())
            throw InvalidComponentType();
        return it->second();
    }
}
