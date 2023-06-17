#include "reng.hpp"

int main(int argc, char const *argv[])
{
    constexpr int WIDTH = 500;
    constexpr int HEIGHT = 500;

    reng::Box box(reng::Attributes("Dancing Box", 0, 0, WIDTH, HEIGHT, false));

    sf::CircleShape shape(70, 4);
    shape.move(WIDTH /2 -70, HEIGHT /2 -70);
    shape.setFillColor(sf::Color::Red);

    box.addElement(&shape);

    bool flag = true;

    reng::reng(box, [&flag, &shape](auto& window, auto& event) {
        if (!window.pollEvent(event)) return;
        if (shape.getPosition() == sf::Vector2f(5, 5)) flag = true;
        if (shape.getPosition() == sf::Vector2f(495 -150, 495 -150)) flag = false;
        if (flag) shape.move(1, 1);
        else shape.move(-1, -1);
        reng::Flags::reRender = true;
    });

    return 0;
}
