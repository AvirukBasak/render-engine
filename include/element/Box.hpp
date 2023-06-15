#ifndef BOX_HPP
#define BOX_HPP

#include "Element.hpp"
#include <SFML/Graphics.hpp>
#include <string>
#include <list>

namespace reng
{
    class Box : public Element
    {
        float cornerRadius = 10.f;  // Corner radius for the box
        std::list<Element*> elements;  // Linked list of elements

    public:
        // Constructor
        Box(int x, int y, int width, int height, bool hidden, const std::string& content);

        // Render the box and its elements
        void render(sf::RenderWindow& window) override;

        // Add an element to the linked list
        void addElement(Element* element);
    };
}

#endif // BOX_HPP
