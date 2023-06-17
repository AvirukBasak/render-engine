#ifndef RENDER_HPP
#define RENDER_HPP

#include <functional>
#include "element/Box.hpp"

namespace reng
{
    void reng(Box box, std::function<void (sf::Window& window)> callback = nullptr);
};

#endif // RENDER_HPP
