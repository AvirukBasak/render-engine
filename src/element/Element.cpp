#include "element/Element.hpp"

using namespace reng;

Element::Element(Attributes attributes)
    : attr(attributes) {}


std::string Element::getName(){
    return attr.name;
}

int Element::getPosnX() {
    return attr.posnx;
}

int Element::getPosnY() {
    return attr.posny;
}

int Element::getWidth() {
    return attr.width;
}

int Element::getHeight() {
    return attr.height;
}

bool Element::isHidden() {
    return attr.hidden;
}

void Element::setPosnX(int x) {
    attr.posnx = x;
}

void Element::setPosnY(int y) {
    attr.posny = y;
}

void Element::moveTo(int x, int y) {
    attr.posnx = x;
    attr.posny = y;
}

void Element::moveBy(int dx, int dy) {
    attr.posnx += dx;
    attr.posny += dy;
}

void Element::setWidth(int width) {
    attr.width = width;
}

void Element::setHeight(int height) {
    attr.height = height;
}

/** Sets the width and height to new values */
void Element::resize(int width, int height) {
    attr.width = width;
    attr.height = height;
}

/** Increments the width and height by given values */
void Element::scale(int dWidth, int dHeight) {
    attr.width += dWidth;
    attr.height += dHeight;
}

/** Scales the image by a multiplier */
void Element::scale(int multiplier) {
    attr.width *= multiplier;
    attr.height *= multiplier;
}

void Element::hide() {
    attr.hidden = true;
}

void Element::show() {
    attr.hidden = false;
}

void Element::toggleVisibility() {
    attr.hidden ^= true;
}
