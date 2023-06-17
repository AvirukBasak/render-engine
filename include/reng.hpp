#ifndef RENDER_HPP
#define RENDER_HPP

#include <functional>
#include "element/Box.hpp"
#include "element/config/Flags.hpp"

namespace reng
{
    void reng(Box box, std::function<void (sf::Window& window)> callback, std::function<void (sf::Event& event)> handler = nullptr);
};

#endif // RENDER_HPP
