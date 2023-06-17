#ifndef ATTRIBUTES_HPP
#define ATTRIBUTES_HPP

#include <string>
#include <functional>

namespace reng
{
    class Attributes
    {
    public:
        std::string name;
        float posnx;
        float posny;
        float width;
        float height;
        bool hidden;
        std::function<void (void)> callback;

        Attributes(float posnx, float posny, float width, float height);
        Attributes(const std::string& name, float posnx, float posny, float width, float height, bool hidden);
        Attributes(const std::string& name, float posnx, float posny, float width, float height, bool hidden, std::function<void (void)> callback);
    };
}

#endif
