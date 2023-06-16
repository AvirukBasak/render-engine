#include <reng.hpp>

using namespace reng;

void reng::reng(Box box, std::function<void (sf::Window& window)> callback)
{
    sf::RenderWindow window(sf::VideoMode(box.getWidth(), box.getHeight()), box.getName());

    box.render(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // updates callback function
            if (callback) callback(window);
        }
        // window.clear();
        // if (!box.isHidden()) box.render(window);
        window.display();
    }
}
