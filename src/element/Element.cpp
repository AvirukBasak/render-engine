#include "element/Element.hpp"
#include "element/config/Flags.hpp"

using namespace reng;

Element::Element(Attributes attributes)
    : attr(attributes) {}

Element::~Element() {}

std::string Element::getName() const {
    return attr.name;
}

float Element::getPosnX() const {
    return attr.posnx;
}

float Element::getPosnY() const {
    return attr.posny;
}

float Element::getWidth() const {
    return attr.width;
}

float Element::getHeight() const {
    return attr.height;
}

bool Element::isHidden() const {
    return attr.hidden;
}

void Element::setPosnX(int x) {
    attr.posnx = x;
    reng::Flags::reRender = true;
}

void Element::setPosnY(int y) {
    attr.posny = y;
    reng::Flags::reRender = true;
}

void Element::moveTo(int x, int y) {
    attr.posnx = x;
    attr.posny = y;
    reng::Flags::reRender = true;
}

void Element::moveBy(float dx, float dy) {
    attr.posnx += dx;
    attr.posny += dy;
    reng::Flags::reRender = true;
}

void Element::setWidth(int width) {
    attr.width = width;
    reng::Flags::reRender = true;
}

void Element::setHeight(int height) {
    attr.height = height;
    reng::Flags::reRender = true;
}

/** Sets the width and height to new values */
void Element::resizeTo(int width, int height) {
    attr.width = width;
    attr.height = height;
    reng::Flags::reRender = true;
}

/** Increments the width and height by given values */
void Element::resizeBy(float dWidth, float dHeight) {
    attr.width += dWidth;
    attr.height += dHeight;
    reng::Flags::reRender = true;
}

/** Scales the image by a multiplier */
void Element::scale(float multiplier) {
    attr.width = attr.width * multiplier;
    attr.height = attr.height * multiplier;
    reng::Flags::reRender = true;
}

void Element::hide() {
    attr.hidden = true;
    reng::Flags::reRender = true;
}

void Element::show() {
    attr.hidden = false;
    reng::Flags::reRender = true;
}

void Element::toggleVisibility() {
    attr.hidden ^= true;
    reng::Flags::reRender = true;
}
