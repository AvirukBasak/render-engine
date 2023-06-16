#include "element/Box.hpp"

using namespace reng;

// Constructor
Box::Box(Attributes attributes)
    : Element(attributes) {}

// Render the box and its elements
void Box::render(sf::RenderWindow& window)
{
    if (this->isHidden()) return;

    // Create the box shape
    sf::RectangleShape boxShape;
    boxShape.setSize(sf::Vector2f(this->getWidth(), this->getHeight()));
    boxShape.setPosition(this->getPosnX(), this->getPosnY());

    // Set the background color
    boxShape.setFillColor(sf::Color(0xF7, 0xF7, 0xF7)); // Default: white-ish

    // Set the border color and thickness
    boxShape.setOutlineColor(sf::Color(0xDE, 0xDE, 0xDE)); // Default: darker white
    boxShape.setOutlineThickness(1.f);

    // Set the border radius (rounded corners): this doesn't exist in SFML 2.4.2
    // sf::Vector2f cornerRadii(cornerRadius, cornerRadius);
    // boxShape.setCornerRadii(cornerRadii);

    // Render the box
    window.draw(boxShape);

    // Render the elements
    for (auto element : elements) {
        element->render(window);
    }
}

// Add an element to the linked list
void Box::addElement(Element* element)
{
    elements.push_back(element);
}
