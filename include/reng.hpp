#ifndef RENDER_HPP
#define RENDER_HPP

#include <functional>
#include "element/Box.hpp"
#include "element/config/Flags.hpp"

namespace reng
{
    void reng(Box &box, std::function<void (sf::Window &)> callback,
              std::function<void (sf::Event &)> handler = nullptr);
};

#endif // RENDER_HPP
