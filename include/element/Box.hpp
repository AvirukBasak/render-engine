#ifndef BOX_HPP
#define BOX_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <list>

#include "Element.hpp"

namespace reng
{
    class Box : public Element
    {
        sf::RectangleShape boxShape;

        // reason map isn't used: order of pushing into list is maintained
        // reason vector isn't used: list insertions and deletions are faster
        std::list<std::shared_ptr<Element>> elements;
        std::list<std::shared_ptr<sf::Shape>> shapes;

    public:
        Box(Attributes attributes);
        void render(sf::RenderWindow& window) override;
        void addElement(const Element* element);
        void addElement(const sf::Shape* shape);
        void removeElement(const Element* element);
        void removeElement(const sf::Shape* shape);
        // overriden
        void setPosnX(int x);
        void setPosnY(int y);
        void moveTo(int x, int y);
        void moveBy(int dx, int dy);
        void setWidth(int width);
        void setHeight(int height);
        /** Sets the width and height to new values */
        void resizeTo(int width, int height);
        /** Increments the width and height by given values */
        void resizeBy(int dWidth, int dHeight);
        /** Scales the image by a multiplier */
        void scale(double multiplier);
    };
}

#endif // BOX_HPP
