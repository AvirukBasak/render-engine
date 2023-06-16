#include <string>
#include <functional>

namespace reng
{
    struct Attributes
    {
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
