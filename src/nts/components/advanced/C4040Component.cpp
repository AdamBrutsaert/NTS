/*
** EPITECH PROJECT, 2024
** C4040Component.cpp
** File description:
** C4040Component.cpp
*/

#include "nts/components/advanced/C4040Component.hpp"

namespace nts {
    C4040Component::C4040Component()
        : _clock(Pin::Type::Input), _reset(Pin::Type::Input)
    {
        for (std::size_t i = 0; i < 12; i++)
            _outputs.emplace_back(Pin::Type::Output);

        _clock.bind([&]() {
            if (_reset.state() != Tristate::False)
                return;
            if (_clock.state() != Tristate::False)
                return;

            // Compute value from pin
            int value = 0;

            for (std::size_t i = 0; i < 12; i++) {
                if (_outputs[i].state() == Tristate::Undefined)
                    return;
                if (_outputs[i].state() == Tristate::True)
                    value += 1 << i;
            }

            // Increment value
            value++;

            // Set value to pins
            for (std::size_t i = 0; i < 12; i++)
                _outputs[i].set(value & (1 << i) ? Tristate::True : Tristate::False);
        });

        _reset.bind([&]() {
            if (_reset.state() != nts::Tristate::True)
                return;
            for (auto &pin : _outputs)
                pin.set(nts::Tristate::False);
        });
    }

    void C4040Component::tick()
    {
    }

    Pin &C4040Component::pin(std::size_t pin)
    {
        if (pin == 1) return _outputs[11];
        if (pin == 2) return _outputs[5];
        if (pin == 3) return _outputs[4];
        if (pin == 4) return _outputs[6];
        if (pin == 5) return _outputs[3];
        if (pin == 6) return _outputs[2];
        if (pin == 7) return _outputs[1];
        if (pin == 9) return _outputs[0];
        if (pin == 10) return _clock;
        if (pin == 11) return _reset;
        if (pin == 12) return _outputs[8];
        if (pin == 13) return _outputs[7];
        if (pin == 14) return _outputs[9];
        if (pin == 15) return _outputs[10];
        throw IComponent::InvalidPin();
    }
}
