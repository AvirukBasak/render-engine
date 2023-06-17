#include "reng.hpp"
#include "element/config/Flags.hpp"

using namespace reng;

void reng::reng(Box box, std::function<void (sf::Window& window)> callback)
{
    sf::RenderWindow window(sf::VideoMode(box.getWidth(), box.getHeight()), box.getName());

    box.render(window);

    // FPS system
    sf::Clock clock;
    sf::Time timeFrame = sf::seconds(1.f / Flags::FPS);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            // updates callback function
            if (callback) callback(window);
        }
        if (clock.getElapsedTime() >= timeFrame) {
            if (Flags::reRender) {
                window.clear();
                box.render(window);
                Flags::reRender = false;
            }
            clock.restart();
            window.display();
        }
    }
}
