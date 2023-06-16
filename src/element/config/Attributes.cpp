#include "element/config/Attributes.hpp"

using namespace reng;

Attributes::Attributes(AttributesT0 attributes)
  : posnx(attributes.posnx),
    posny(attributes.posny),
    width(attributes.width),
    height(attributes.height),
    name(""),
    hidden(false),
    callback {}
{}


Attributes::Attributes(AttributesT1 attributes)
  : posnx(attributes.posnx),
    posny(attributes.posny),
    width(attributes.width),
    height(attributes.height),
    name(attributes.name),
    hidden(attributes.hidden),
    callback {}
{}

Attributes::Attributes(AttributesT2 attributes)
  : posnx(attributes.posnx),
    posny(attributes.posny),
    width(attributes.width),
    height(attributes.height),
    name(attributes.name),
    hidden(attributes.hidden),
    callback(attributes.callback)
{}
