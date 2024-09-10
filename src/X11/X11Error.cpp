#include "X11Error.h"
#include <X11/Xlib.h>
#include <algorithm>
#include <format>
using std::format;

namespace Tina
{
    const char* XRequestErrorCodeToString(int32 code)
    {
        if(code >= 128 && code <= 255) 
        {
            return "Extension Error";
        }

        switch(code)
        {
            case BadRequest: return "BadRequest";
            case BadValue: return "BadValue";
            case BadWindow: return "BadWindow";
            case BadPixmap: return "BadPixmap";
            case BadAtom: return "BadAtom";
            case BadCursor: return "BadCursor";
            case BadFont: return "BadFont";
            case BadMatch: return "BadMatch";
            case BadDrawable: return "BadDrawable";
            case BadAccess: return "BadAccess";
            case BadAlloc: return "BadAlloc";
            case BadColor: return "BadColor";
            case BadGC: return "BadGC";
            case BadIDChoice: return "BadIDChoice";
            case BadName: return "BadName";
            case BadLength: return "BadLength";
            case BadImplementation: return "BadImplementation";
            default: return "Unknow Erro";
        }
    }

    X11Error::X11Error(Display * display,
            const int32 hr, 
            const string_view func, 
            const string_view file, 
            const int32 line) noexcept :
        display{display}, Error{hr, func, file, line}
    {
    }

    string X11Error::ToString() const
    {
        string errorText(64, '\n');
        XErrorEvent e;
        XGetErrorText(display, e.error_code, &errorText[0], 64);

        string message
        {
            format("X Error of failed request: {}\n"
            "Request error code: {}\n"
            "Resource id in failed request: {}\n",
            XRequestErrorCodeToString(hrCode),
            e.error_code,
            e.resourceid)
        };

        return format("{} failed in {}, line {}:\n{}", 
            funcName, fileName, lineNum, message);
    }
}