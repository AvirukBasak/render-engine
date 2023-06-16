#ifndef IMAGEVIEW_HPP
#define IMAGEVIEW_HPP

#include <SFML/Graphics.hpp>
#include <string>

#include "Element.hpp"

namespace reng
{
    class ImageView : Element
    {
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        ImageView(const std::string& imagePath);
        ImageView(const std::string& imagePath, Attributes attributes);
        void render(sf::RenderWindow& window) override;
    };
}

#endif // IMAGEVIEW_HPP
