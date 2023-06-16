#include "reng.hpp"

int main(int argc, char const *argv[])
{
    reng::Box box(reng::Attributes {
        .name = "My Box",
        .posnx = 0,
        .posny = 0,
        .width = 500,
        .height = 500,
        .hidden = false
    });
    return 0;
}
