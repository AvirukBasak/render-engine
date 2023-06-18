#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include <list>

#include "Element.hpp"

namespace reng
{
    /** The Box is a container for other elements.
        It can contain both reng::Element and sf::Shape types.
        On changing the position or dimensions of a Box, updates
            to its children are calculated automatically */
    class Box : public Element
    {
        sf::RectangleShape boxShape;

        /* Reason map isn't used: order of pushing into list is maintained.
           Reason vector isn't used: list insertions and deletions are faster */
        std::list<Element *> elements;
        std::list<sf::Shape *> shapes;

    public:
        Box(Attributes attributes);
        ~Box();
        void render(sf::RenderWindow &window) override;
        void addElement(Element *element);
        void addElement(sf::Shape *shape);
        void removeElement(Element *element);
        void removeElement(sf::Shape *shape);
        // overriden
        void setPosnX(float x);
        void setPosnY(float y);
        void moveTo(float x, float y);
        void moveBy(float dx, float dy);
        void setWidth(float width);
        void setHeight(float height);
        /** Sets the width and height to new values */
        void resizeTo(float width, float height);
        /** Increments the width and height by given values */
        void resizeBy(float dWidth, float dHeight);
        /** Scales the box by a multiplier */
        void scale(float multiplier);
    };
}

#endif // BOX_HPP
