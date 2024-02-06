/*
** EPITECH PROJECT, 2024
** ComponentFactory.cpp
** File description:
** ComponentFactory.cpp
*/

#include "nts/components/ComponentFactory.hpp"

namespace nts {
    std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> ComponentFactory::_components{};

    std::unique_ptr<nts::IComponent> ComponentFactory::createComponent(const std::string& type)
    {
        auto it = ComponentFactory::_components.find(type);
        if (it == ComponentFactory::_components.end())
            throw InvalidComponentType();
        return it->second();
    }
}
