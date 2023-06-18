#include "element/config/Attributes.hpp"

using namespace reng;

Attributes::Attributes(float posnx, float posny, float width, float height)
  : name(nullptr),
    posnx(posnx),
    posny(posny),
    width(width),
    height(height),
    hidden(false),
    callback(nullptr)
{}

Attributes::Attributes(const std::string name, float posnx, float posny,
                       float width, float height, bool hidden)
  : name(name),
    posnx(posnx),
    posny(posny),
    width(width),
    height(height),
    hidden(hidden),
    callback(nullptr)
{}

Attributes::Attributes(const std::string name, float posnx, float posny,
                       float width, float height, bool hidden,
                       std::function<void (void)> callback)
  : name(name),
    posnx(posnx),
    posny(posny),
    width(width),
    height(height),
    hidden(hidden),
    callback(callback)
{}
