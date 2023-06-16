#include <SFML/Graphics.hpp>
#include "config/Attributes.hpp"

namespace reng
{
    class Element
    {
    protected:
        constexpr static float CORNER_RADIUS = 10.f;
        Attributes attr;

    public:
        Element(Attributes attributes);
        virtual void render(sf::RenderWindow& window) = 0;
    };
}
