#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#include <thread>
#include <iostream>

int main(int argc, char** argv) {
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Demo!");
    sf::CircleShape shape(70, 4);
    shape.move(window.getSize().x /2 -70, window.getSize().y /2 -70);
    shape.setFillColor(sf::Color::Green);

    bool flag = true;
    /* auto timer = [&flag, &window, &shape]() -> void {
        while (window.isOpen()) {
            std::cout << shape.getPosition().x << ", " << shape.getPosition().y << std::endl;
        }
    };
    std::thread th(timer); */

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (shape.getPosition() == sf::Vector2f(5, 5)) flag = true;
        if (shape.getPosition() == sf::Vector2f(495 -150, 495 -150)) flag = false;
        if (flag) shape.move(0.5, 0.5);
        else shape.move(-0.5, -0.5);
        window.clear();
        window.draw(shape);
        window.display();
    }

    // th.join();
    return 0;
}
