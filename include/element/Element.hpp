#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <SFML/Graphics.hpp>
#include "config/Attributes.hpp"

namespace reng
{
    /** An abstract class that represents any element in the UI */
    class Element
    {
    protected:
        constexpr static float CORNER_RADIUS = 10.f;
        Attributes attr;

    public:
        Element(Attributes attributes);
        virtual ~Element();
        virtual void render(sf::RenderWindow &window) = 0;
        std::string getName() const;
        float getPosnX() const;
        float getPosnY() const;
        float getWidth() const;
        float getHeight() const;
        bool isHidden() const;
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
        /** Scales the element by a multiplier */
        void scale(float multiplier);
        void hide();
        void show();
        void toggleVisibility();
    };
}

#endif
