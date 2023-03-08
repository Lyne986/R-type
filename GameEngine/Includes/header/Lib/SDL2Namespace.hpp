#ifndef __RT_GAMEENGINE_LIB_SDL2NAMESPACE_HPP__
    #define __RT_GAMEENGINE_LIB_SDL2NAMESPACE_HPP__

namespace RT::GE::Lib::SDL2 {
    class SDL2;
    class Timer;

    namespace Audio {
        class Music;
    }

    namespace Graphic {
        class Renderer;
        class Image;
        class SpriteManager;
        class SpriteSheet;
        class Surface;
        class Text;
        class Texture;
        class Rect;
    };

    namespace Window {
        class Window;
        class Event;
    }

    namespace Audio {
        class Mixer;
        class Music;
        class Sound;
    }
};

#endif