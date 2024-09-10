#ifndef X11_ERROR_H
#define X11_ERROR_H

#include "Error.h"
#include <X11/Xlib.h>

namespace Tina
{
    class X11Error final : public Error
    {
    private:
        Display * display;

    public:
        X11Error(Display * display,
            const int32 hr, 
            const string_view func, 
            const string_view file, 
            const int32 line) noexcept;
        string ToString() const override;
    };
}

#ifndef X11ThrowIfFailed
#define X11ThrowIfFailed(display, x)                                               \
{                                                                                  \
    int32 hr = (x);                                                                \
    if(hr != 0) { throw X11Error(display, hr, __func__, __FILE__, __LINE__); }     \
}
#endif

#endif