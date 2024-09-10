#ifndef TIMER_H
#define TIMER_H

#include "Types.h"
#include <ctime>

namespace Tina
{
    class Timer final
    {
    private:
        timespec start, end;
        bool stoped;
        
    public:
        Timer() noexcept;

        void Start() noexcept;
        void Stop() noexcept;
        double Reset() noexcept;
        
        double Elapsed() noexcept;
        bool Elapsed(const double secs) noexcept;
        
        uint64 Stamp() noexcept;
        
        double Elapsed(const uint64 stamp) noexcept;
        bool Elapsed(const uint64 stamp, const double secs) noexcept;
    };

    inline bool Timer::Elapsed(const double secs) noexcept
    { return (Elapsed() >= secs ? true : false); }

    inline bool Timer::Elapsed(const uint64 stamp, const double secs) noexcept
    { return (Elapsed(stamp) >= secs ? true : false); }

    inline uint64 Timer::Stamp() noexcept
    {
        clock_gettime(CLOCK_MONOTONIC, &end);
        return static_cast<uint64>(end.tv_sec) * static_cast<uint64>(1E9) + static_cast<uint64>(end.tv_nsec);
    }
}

#endif