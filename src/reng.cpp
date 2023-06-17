#include "reng.hpp"

using namespace reng;

void reng::reng(Box box, std::function<void (sf::Window& window)> callback, std::function<void (sf::Event& event)> handler)
{
    sf::RenderWindow window(sf::VideoMode(box.getWidth(), box.getHeight()), box.getName());

    box.render(window);

    // FPS system
    sf::Clock clock;
    sf::Time timeFrame = sf::seconds(1.f / Flags::FPS);

    while (window.isOpen()) {
        sf::Event event;
        /* Left the event loop outside the timing logic on ChatGPT's suggestion
           It said that handling events as soon as they occur will make the app more responsive */
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (handler) handler(event);
        }
        // Timing logic ensures updates and renders are done Flags::FPS times a second only
        if (clock.getElapsedTime() >= timeFrame) {
            // updates callback function
            if (callback) callback(window);
            /* Render only if this flag is set
               This flag is kept false if there are no changes to be rendered */
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
