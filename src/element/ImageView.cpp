#include <iostream>
#include "element/ImageView.hpp"

using namespace reng;

ImageView::ImageView(const std::string imagePath, Attributes attributes, const std::string label)
    : imagePath(imagePath), Element(attributes), label(label)
{
    if (!imagePath.empty()) {
        if (!texture.loadFromFile(imagePath)) {
            std::cout << "Failed to load image: " << imagePath << std::endl;
        } else {
            sprite.setTexture(texture);
            sprite.setPosition(attr.posnx, attr.posny);
            sprite.setScale(static_cast<float>(attr.width) / texture.getSize().x,
                            static_cast<float>(attr.height) / texture.getSize().y);
        }
    }
}

void ImageView::render(sf::RenderWindow& window)
{
    if (attr.hidden || texture.getSize().x == 0 || texture.getSize().y == 0)
        return;

    // Render the image
    window.draw(sprite);

    // Render the content as a label
    if (!label.empty()) {
        sf::Text labelText(label, sf::Font(), 12);
        labelText.setPosition(attr.posnx, attr.posny + attr.height + 5);  // Position the label below the image
        window.draw(labelText);
    }
}
