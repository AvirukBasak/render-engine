#include <reng.hpp>

void reng::reng(Box box, int width, int height, std::function<void (sf::Window& window)> callback)
{
    sf::RenderWindow window(sf::VideoMode(width, height), "Box Example");

    // Render the Box and its elements
    box.render(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            callback(window);
        }
        window.display();
    }
}
