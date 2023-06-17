#include <stdexcept>
#include "element/ImageView.hpp"
#include "element/config/Flags.hpp"

using namespace reng;

ImageView::ImageView(const std::string imagePath, const std::string label)
    : imagePath(imagePath), Element({0, 0, 0, 0}), label(label)
{
    if (imagePath.empty())
        throw std::invalid_argument("ImageView::ImageView(imagePath, label): imagePath is empty");
    if (!texture.loadFromFile(imagePath))
        throw std::invalid_argument("ImageView::ImageView(imagePath, label): file not found");
    sprite.setTexture(texture);
    sprite.setPosition(this->getPosnX(), this->getPosnY());
    this->resize(texture.getSize().x, texture.getSize().y);
    sprite.setScale(1, 1);
}

ImageView::ImageView(const std::string imagePath, Attributes attributes, const std::string label)
    : imagePath(imagePath), Element(attributes), label(label)
{
    if (imagePath.empty())
        throw std::invalid_argument("ImageView::ImageView(imagePath, label): imagePath is empty");
    if (!texture.loadFromFile(imagePath))
        throw std::invalid_argument("ImageView::ImageView(imagePath, label): file not found");
    sprite.setTexture(texture);
    sprite.setPosition(this->getPosnX(), this->getPosnY());
    sprite.setScale(static_cast<float>(this->getWidth()) / texture.getSize().x,
                    static_cast<float>(this->getHeight()) / texture.getSize().y);
}

void ImageView::render(sf::RenderWindow& window)
{
    reng::Flags::reRender = false;

    if (this->isHidden() || texture.getSize().x == 0 || texture.getSize().y == 0)
        return;

    sprite.setPosition(this->getPosnX(), this->getPosnY());
    sprite.setScale(static_cast<float>(this->getWidth()) / texture.getSize().x,
                    static_cast<float>(this->getHeight()) / texture.getSize().y);

    // Render the image
    window.draw(sprite);

    // Render the content as a label
    if (!label.empty()) {
        sf::Text labelText(label, sf::Font(), 12);
        // Position the label below the image
        labelText.setPosition(this->getPosnX(), this->getPosnY() + this->getHeight() + 5);
        window.draw(labelText);
    }
}
