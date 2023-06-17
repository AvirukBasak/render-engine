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
        int posnx;
        int posny;
        int width;
        int height;
        bool hidden;
        std::function<void (void)> callback;

        Attributes(int posnx, int posny, int width, int height);
        Attributes(const std::string& name, int posnx, int posny, int width, int height, bool hidden);
        Attributes(const std::string& name, int posnx, int posny, int width, int height, bool hidden, std::function<void (void)> callback);
    };
}

#endif
