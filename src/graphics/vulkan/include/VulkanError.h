#ifndef VULKAN_ERROR_H
#define VULKAN_ERROR_H

#include "Types.h"
#include "Error.h"

namespace Tina
{
    class VulkanError final : public Error
    {
    public:
        VulkanError(const int32 hr, const string_view func, const string_view file, const int32 line) noexcept;
        string ToString() const override;
    };
}

#ifndef VkThrowIfFailed
#define VkThrowIfFailed(x)                                                   \
{                                                                            \
    int32 hr = (x);                                                          \
    if(hr != 0) { throw VulkanError(hr, __func__, __FILE__, __LINE__); }     \
}
#endif

#endif