#ifndef IMAGEVIEW_HPP
#define IMAGEVIEW_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Element.hpp"

namespace reng
{
    class ImageView : public Element
    {
        std::string imagePath;
        std::string label;
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        ImageView(const std::string imagePath, const std::string label = "");
        ImageView(const std::string imagePath, Attributes attributes, const std::string label = "");
        void render(sf::RenderWindow& window) override;
    };
}

#endif // IMAGEVIEW_HPP
