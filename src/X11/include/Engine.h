#ifndef ENGINE_H
#define ENGINE_H

#include "Game.h"

namespace Tina
{
    class Engine final
    {
    private:
        int32 Loop() noexcept;
        bool Quit(XEvent * event) const noexcept;
        static inline Atom WM_DELETE_WINDOW;

    public:
        static Graphics * graphics;
        static Window * window;
        static Input * input;
        static Game * game;

        Engine() noexcept;
        ~Engine() noexcept;

        int32 Start(Game* game);
    };

    inline bool Engine::Quit(XEvent * event) const noexcept
    { return event->type == ClientMessage && event->xclient.data.l[0] == WM_DELETE_WINDOW; }
}

#endif