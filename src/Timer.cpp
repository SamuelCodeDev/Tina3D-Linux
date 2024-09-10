#include "Timer.h"

namespace Tina
{
    Timer::Timer() noexcept : stoped{false}
    {
    }

    void Timer::Start() noexcept
    {
        if (stoped)
        {
            uint64 elapsed = (uint64(end.tv_sec) * uint64(1E9) + uint64(end.tv_nsec)) -
                              (uint64(start.tv_sec) * uint64(1E9) + uint64(start.tv_nsec));
            clock_gettime(CLOCK_MONOTONIC, &start);
            start.tv_sec -= elapsed / uint64(1E9);
            start.tv_nsec -= static_cast<long>(elapsed % uint64(1E9));
            stoped = false;
        }
        else
        {
            clock_gettime(CLOCK_MONOTONIC, &start);
        }
    }

    void Timer::Stop() noexcept
    {
        if (!stoped)
        {
            clock_gettime(CLOCK_MONOTONIC, &end);
            stoped = true;
        }
    }

    double Timer::Reset() noexcept
    {
        if (stoped)
        {
            uint64 elapsed = (uint64(end.tv_sec) * uint64(1E9) + uint64(end.tv_nsec)) -
                              (uint64(start.tv_sec) * uint64(1E9) + uint64(start.tv_nsec));
            clock_gettime(CLOCK_MONOTONIC, &start);
            stoped = false;
            return static_cast<double>(elapsed) / 1E9;
        }
        else
        {
            clock_gettime(CLOCK_MONOTONIC, &end);
            uint64 elapsed = (uint64(end.tv_sec) * uint64(1E9) + uint64(end.tv_nsec)) -
                            (uint64(start.tv_sec) * uint64(1E9) + uint64(start.tv_nsec));
            start = end;
            return static_cast<double>(elapsed) / 1E9;
        }
    }

    double Timer::Elapsed() noexcept
    {
        if (stoped)
        {
            auto elapsed = (uint64(end.tv_sec) * uint64(1E9) + uint64(end.tv_nsec)) -
                            (uint64(start.tv_sec) * uint64(1E9) + uint64(start.tv_nsec));
            return static_cast<double>(elapsed) / 1E9;
        }
        else
        {
            clock_gettime(CLOCK_MONOTONIC, &end);
            auto elapsed = (uint64(end.tv_sec) * uint64(1E9) + uint64(end.tv_nsec)) -
                            (uint64(start.tv_sec) * uint64(1E9) + uint64(start.tv_nsec));
            return static_cast<double>(elapsed) / 1E9;
        }
    }

    double Timer::Elapsed(const uint64 stamp) noexcept
    {
        if (stoped)
        {
            auto elapsed = (uint64(end.tv_sec) * uint64(1E9) + uint64(end.tv_nsec)) - stamp;
            return static_cast<double>(elapsed) / 1E9;
        }
        else
        {
            clock_gettime(CLOCK_MONOTONIC, &end);
            auto elapsed = (uint64(end.tv_sec) * uint64(1E9) + uint64(end.tv_nsec)) - stamp;
            return static_cast<double>(elapsed) / 1E9;
        }
    }
}