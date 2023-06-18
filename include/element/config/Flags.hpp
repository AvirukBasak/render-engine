#ifndef FLAGS_HPP
#define FLAGS_HPP

namespace reng
{
    /** A bunch of flags that can configure the behaviour of the engine. */
    class Flags
    {
    public:
        /** Renders current graphics state if set to true.
            Is set to false on every render. */
        static bool reRender;
        /** Clears window before drawing graphics if set to true.
            By default is set to true. */
        static bool clearWindow;
        /** Frame rate or frames per second.
            By default is set to 60. */
        static int FPS;
    };
}

#endif
