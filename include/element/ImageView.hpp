#ifndef IMAGEVIEW_HPP
#define IMAGEVIEW_HPP

#include <SFML/Graphics.hpp>
#include <string>
#include "Element.hpp"

namespace reng
{
    /** The ImageView conatains and displays an image along with an optional label */
    class ImageView : public Element
    {
        const std::string imagePath;
        sf::Text labelText;
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        ImageView(const std::string imagePath, const std::string label = "");
        ImageView(const std::string imagePath, Attributes attributes,
                  const std::string label = "");
        void render(sf::RenderWindow &window) override;
    };
}

#endif // IMAGEVIEW_HPP
