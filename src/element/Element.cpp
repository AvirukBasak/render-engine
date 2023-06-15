#include "element/Element.hpp"

Element::Element(int x, int y, int width, int height, bool hidden, const std::string& content)
    : x(x), y(y), width(width), height(height), hidden(hidden), content(content) {}
