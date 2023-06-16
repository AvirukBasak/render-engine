#include <string>
#include <functional>

namespace reng
{
    struct AttributesT0
    {
        int posnx;
        int posny;
        int width;
        int height;
    };

    struct AttributesT1 : public AttributesT0
    {
        std::string name;
        bool hidden;
    };

    struct AttributesT2 : public AttributesT1
    {
        std::function<void (void)> callback;
    };

    struct Attributes : public AttributesT2
    {
        Attributes(AttributesT0 attr);
        Attributes(AttributesT1 attr);
        Attributes(AttributesT2 attr);
    };
}
