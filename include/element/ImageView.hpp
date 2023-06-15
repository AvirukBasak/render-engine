#ifndef IMAGEVIEW_HPP
#define IMAGEVIEW_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Element.hpp" // Include the Element class header file

namespace reng
{
    class ImageView : public Element
    {
        sf::Texture texture;
        sf::Sprite sprite;

    public:
        ImageView(int x, int y, int width, int height, bool hidden, const std::string& label, const std::string& imagePath);
        void render(sf::RenderWindow& window) override;
    };
}

#endif // IMAGEVIEW_HPP
