#ifndef ERROR_H
#define ERROR_H

#include "Types.h"

namespace Tina
{
    class Error
    {
    protected:
        int32 hrCode;             
        string funcName;            
        string fileName;            
        int lineNum;                
        
    public:
        Error() noexcept;
        Error(const int32 hr, const string_view func, const string_view file, const int32 line) noexcept;
        virtual string ToString() const;
    };
}

#ifndef ThrowIfFailed
#define ThrowIfFailed(x)                                               \
{                                                                      \
    int32 hr = (x);                                                    \
    if(hr != 0) { throw Error(hr, __func__, __FILE__, __LINE__); }     \
}
#endif

#endif