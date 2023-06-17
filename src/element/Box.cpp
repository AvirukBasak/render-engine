#include "element/Box.hpp"
#include "element/config/Flags.hpp"

using namespace reng;

// Constructor
Box::Box(Attributes attributes)
    : Element(attributes)
{
    // Create the box shape
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
}

Box::~Box()
{
    elements.clear();
    shapes.clear();
}

// Render the box and its elements
void Box::render(sf::RenderWindow& window)
{
    reng::Flags::reRender = false;

    if (this->isHidden()) return;

    boxShape.setSize(sf::Vector2f(this->getWidth(), this->getHeight()));
    boxShape.setPosition(this->getPosnX(), this->getPosnY());

    // Render the box
    window.draw(boxShape);

    // Render the elements
    for (auto element : elements)
        element->render(window);

    // Render SFML shapes
    for (auto shape : shapes)
        window.draw(*shape);
}

void Box::addElement(Element* element)
{
    elements.push_back(element);
}

void Box::addElement(sf::Shape* shape)
{
    shapes.push_back(shape);
}

void Box::removeElement(Element* element)
{
    elements.remove(element);
}

void Box::removeElement(sf::Shape* shape)
{
    shapes.remove(shape);
}

// overriden

void Box::setPosnX(int x)
{
    // update for the elements
    for (auto element : elements) {
        int x_this = this->getPosnX();
        int x_element = element->getPosnX();
        // Set children posnx accordingly
        element->setPosnX(x + (x_this - x_element));
    }
    // update for the shapes
    for (auto shape : shapes) {
        int x_this = this->getPosnX();
        int x_shape = shape->getPosition().x;
        // Set children posnx accordingly
        shape->setPosition(x + (x_this - x_shape), shape->getPosition().y);
    }
    // must be placed after updates to children
    Element::setPosnX(x);
}

void Box::setPosnY(int y)
{
    // update for the elements
    for (auto element : elements) {
        int y_this = this->getPosnY();
        int y_element = element->getPosnY();
        // Set children posny accordingly
        element->setPosnX(y + (y_this - y_element));
    }
    // update for the shapes
    for (auto shape : shapes) {
        int y_this = this->getPosnY();
        int y_shape = shape->getPosition().y;
        // Set children posnx accordingly
        shape->setPosition(shape->getPosition().x, y + (y_this - y_shape));
    }
    // must be placed after updates to children
    Element::setPosnY(y);
}

void Box::moveTo(int x, int y)
{
    // update for the elements
    for (auto element : elements) {
        int x_this = this->getPosnX();
        int x_element = element->getPosnX();
        int y_this = this->getPosnY();
        int y_element = element->getPosnY();
        // Set children posn accordingly
        element->moveTo(x + (x_this - x_element), y + (y_this - y_element));
    }
    // update for the shapes
    for (auto shape : shapes) {
        int x_this = this->getPosnX();
        int x_shape = shape->getPosition().x;
        int y_this = this->getPosnY();
        int y_shape = shape->getPosition().y;
        // Set children posn accordingly
        shape->setPosition(x + (x_this - x_shape), y + (y_this - y_shape));
    }
    // must be placed after updates to children
    Element::moveTo(x, y);
}

void Box::moveBy(float dx, float dy)
{
    // update for the elements
    for (auto element : elements)
        element->moveBy(dx, dy);
    // update for the shapes
    for (auto shape : shapes)
        shape->move(dx, dy);
    // must be placed after updates to children
    Element::moveBy(dx, dy);
}

void Box::setWidth(int width)
{
    // update for the elements
    for (auto element : elements) {
        int w_this = this->getWidth();
        int w_element = element->getWidth();
        // Set children width accordingly
        element->setWidth(width + (w_this - w_element));
    }
    // update for the shapes
    for (auto shape : shapes) {
        int w_this = this->getWidth();
        int w_shape = shape->getLocalBounds().width;
        /* Set children width accordingly:
           Multiply (new dimension / current) with the current to get new */
        shape->setScale((width + (w_this - w_shape)) / w_shape, 1.f);
    }
    // must be placed after updates to children
    Element::setWidth(width);
}

void Box::setHeight(int height)
{
    // update for the elements
    for (auto element : elements) {
        int h_this = this->getHeight();
        int h_element = element->getHeight();
        // Set children height accordingly
        element->setHeight(height + (h_this - h_element));
    }
    // update for the shapes
    for (auto shape : shapes) {
        int h_this = this->getHeight();
        int h_shape = shape->getLocalBounds().height;
        /* Set children width accordingly:
           Multiply (new dimension / current) with the current to get new */
        shape->setScale(1.f, (height + (h_this - h_shape)) / h_shape);
    }
    // must be placed after updates to children
    Element::setHeight(height);
}

/** Sets the width and height to new values */
void Box::resizeTo(int width, int height)
{
    // update for the elements
    for (auto element : elements) {
        int w_this = this->getWidth();
        int w_element = element->getWidth();
        int h_this = this->getHeight();
        int h_element = element->getHeight();
        // Set children dimension accordingly
        element->resizeTo(width + (w_this - w_element),
                          height + (h_this - h_element));
    }
    // update for the shapes
    for (auto shape : shapes) {
        int w_this = this->getWidth();
        int w_shape = shape->getLocalBounds().width;
        int h_this = this->getHeight();
        int h_shape = shape->getLocalBounds().height;
        /* Set children width accordingly:
           Multiply (new dimension / current) with the current to get new */
        shape->setScale((width + (w_this - w_shape)) / w_shape,
                        (height + (h_this - h_shape)) / h_shape);
    }
    // must be placed after updates to children
    Element::resizeTo(width, height);
}

/** Increments the width and height by given values */
void Box::resizeBy(float dWidth, float dHeight)
{
    // update for the elements
    for (auto element : elements)
        element->resizeBy(dWidth, dHeight);
    // update for the shapes
    for (auto shape : shapes) {
        int w_shape = shape->getLocalBounds().width;
        int h_shape = shape->getLocalBounds().height;
        shape->setScale((w_shape + dWidth) / w_shape,
                        (h_shape + dHeight) / h_shape);
    }
    // must be placed after updates to children
    Element::resizeBy(dWidth, dHeight);
}

/** Scales the image by a multiplier */
void Box::scale(float multiplier)
{
    // update for the elements
    for (auto element : elements)
        element->scale(multiplier);
    // update for the shapes
    for (auto shape : shapes)
        shape->setScale(multiplier, multiplier);
    // must be placed after updates to children
    Element::scale(multiplier);
}
