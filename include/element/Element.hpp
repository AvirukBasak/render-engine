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
        std::string getName() const;
        int getPosnX() const;
        int getPosnY() const;
        int getWidth() const;
        int getHeight() const;
        bool isHidden() const;
        void setPosnX(int x);
        void setPosnY(int y);
        void moveTo(int x, int y);
        void moveBy(int dx, int dy);
        void setWidth(int width);
        void setHeight(int height);
        /** Sets the width and height to new values */
        void resize(int width, int height);
        /** Increments the width and height by given values */
        void scale(int dWidth, int dHeight);
        /** Scales the element by a multiplier */
        void scale(double multiplier);
        void hide();
        void show();
        void toggleVisibility();
    };
}
