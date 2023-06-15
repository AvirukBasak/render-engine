#include "element/ImageView.hpp"

using namespace reng;

ImageView::ImageView(int x, int y, int width, int height, bool hidden, const std::string& label, const std::string& imagePath)
    : Element(x, y, width, height, hidden, label)
{
    if (!imagePath.empty()) {
        if (!texture.loadFromFile(imagePath)) {
            std::cout << "Failed to load image: " << imagePath << std::endl;
        } else {
            sprite.setTexture(texture);
            sprite.setPosition(x, y);
            sprite.setScale(static_cast<float>(width) / texture.getSize().x,
                            static_cast<float>(height) / texture.getSize().y);
        }
    }
}

void ImageView::render(sf::RenderWindow& window)
{
    if (hidden || texture.getSize().x == 0 || texture.getSize().y == 0)
        return;

    // Render the image
    window.draw(sprite);

    // Render the content as a label
    if (!content.empty()) {
        sf::Text labelText(content, sf::Font(), 12);
        labelText.setPosition(x, y + height + 5);  // Position the label below the image
        window.draw(labelText);
    }
}
