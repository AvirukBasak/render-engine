#ifndef RENDER_HPP
#define RENDER_HPP

#include <functional>
#include "element/Box.hpp"
#include "element/config/Flags.hpp"

namespace reng
{
    void reng(Box box, std::function<void (sf::Window& window, sf::Event& event)> callback = nullptr);
};

#endif // RENDER_HPP
