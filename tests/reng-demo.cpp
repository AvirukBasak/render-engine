#include "reng.hpp"

int main(int argc, char const *argv[])
{
    reng::Box box(reng::Attributes("My Box", 0, 0, 500, 500, false));
    reng::reng(box);
    return 0;
}
