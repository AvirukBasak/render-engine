#include "element/config/Attributes.hpp"

using namespace reng;

Attributes::Attributes(int posnx, int posny, int width, int height)
  : name(nullptr),
    posnx(posnx),
    posny(posny),
    width(width),
    height(height),
    hidden(false),
    callback(nullptr)
{}

Attributes::Attributes(const std::string& name, int posnx, int posny, int width, int height, bool hidden)
  : name(name),
    posnx(posnx),
    posny(posny),
    width(width),
    height(height),
    hidden(hidden),
    callback(nullptr)
{}

Attributes::Attributes(const std::string& name, int posnx, int posny, int width, int height, bool hidden, std::function<void (void)> callback)
  : name(name),
    posnx(posnx),
    posny(posny),
    width(width),
    height(height),
    hidden(hidden),
    callback(callback)
{}
