#ifndef RENDER_HPP
#define RENDER_HPP

#include <element/Box.hpp>
#include <functional>

namespace reng
{
    void reng(Box& box, int width, int height, std::function<void (sf::Window& window)> callback = {});
};

#endif // RENDER_HPP
