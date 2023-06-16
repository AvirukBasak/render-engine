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
        std::string getName();
        int getPosnX();
        int getPosnY();
        int getWidth();
        int getHeight();
        bool isHidden();
        void setPosnX(int x);
        void setPosnY(int y);
        void moveTo(int x, int y);
        void moveBy(int dx, int dy);
        void setWidth(int width);
        void setHeight(int height);
        /** Sets the width and height to new values */
        void resize(int width, int height);
        /** Increments the width and height by given values */
        void scale(int d_width, int d_height);
        /** Scales the image by a multiplier */
        void scale(int multiplier);
        void hide();
        void show();
        void toggleVisibility();
    };
}
