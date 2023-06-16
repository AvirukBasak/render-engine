#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <list>

#include "Element.hpp"

namespace reng
{
    class Box : Element
    {
        std::list<Element*> elements;

    public:
        Box(Attributes attributes);
        void render(sf::RenderWindow& window) override;
        void addElement(Element* element);
    };
}

#endif // BOX_HPP
