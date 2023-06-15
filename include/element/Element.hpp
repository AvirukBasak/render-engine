#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

class Element
{
protected:
    int x, y;
    int width, height;
    bool hidden;
    std::string content;
    std::list<Element*> elements;

public:
    Element(int x, int y, int width, int height, bool hidden, const std::string& content);
    virtual void render(sf::RenderWindow& window) = 0;
};
