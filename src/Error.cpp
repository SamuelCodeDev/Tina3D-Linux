#include "Error.h"
#include <cstring>
#include <format>
using std::format;
using std::move;

namespace Tina
{
    Error::Error() noexcept : hrCode{}, lineNum{-1}
    {
    }

    Error::Error(const int32 hr, const string_view func, const string_view file, const int32 line) noexcept
        : hrCode{hr}, funcName{move(func)}, lineNum{move(line)}
    {
        auto pos = file.find_last_of('/');

        if (pos != string::npos)
            fileName = file.substr(pos + 1);
    }

    string Error::ToString() const
    {
        return format("{} failed in {}, line {}: \n{}", 
            funcName, fileName, lineNum, strerror(hrCode));
    }
}