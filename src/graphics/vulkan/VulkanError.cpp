#include "VulkanError.h"
#include <vulkan/vulkan_core.h>
#include <format>
using std::format;

namespace Tina
{
    const char* VkRequestErrorCodeToString(const int32 code)
    {
        switch(code)
        {
            case VK_NOT_READY: return "VK_NOT_READY";
            case VK_TIMEOUT: return "VK_TIMEOUT";
            case VK_EVENT_SET: return "VK_EVENT_SET";
            case VK_EVENT_RESET: return "VK_EVENT_RESET";
            case VK_INCOMPLETE: return "VK_INCOMPLETE";
            case VK_ERROR_OUT_OF_HOST_MEMORY: return "VK_ERROR_OUT_OF_HOST_MEMORY";
            case VK_ERROR_OUT_OF_DEVICE_MEMORY: return "VK_ERROR_OUT_OF_DEVICE_MEMORY";
            case VK_ERROR_INITIALIZATION_FAILED: return "VK_ERROR_INITIALIZATION_FAILED";
            case VK_ERROR_DEVICE_LOST: return "VK_ERROR_DEVICE_LOST";
            case VK_ERROR_MEMORY_MAP_FAILED: return "VK_ERROR_MEMORY_MAP_FAILED";
            case VK_ERROR_LAYER_NOT_PRESENT: return "VK_ERROR_LAYER_NOT_PRESENT";
            case VK_ERROR_EXTENSION_NOT_PRESENT: return "VK_ERROR_EXTENSION_NOT_PRESENT";
            case VK_ERROR_FEATURE_NOT_PRESENT: return "VK_ERROR_FEATURE_NOT_PRESENT";
            case VK_ERROR_INCOMPATIBLE_DRIVER: return "VK_ERROR_INCOMPATIBLE_DRIVER";
            case VK_ERROR_TOO_MANY_OBJECTS: return "VK_ERROR_TOO_MANY_OBJECTS";
            case VK_ERROR_FORMAT_NOT_SUPPORTED: return "VK_ERROR_FORMAT_NOT_SUPPORTED";
            case VK_ERROR_FRAGMENTED_POOL: return "VK_ERROR_FRAGMENTED_POOL";
            case VK_ERROR_UNKNOWN: return "VK_ERROR_UNKNOWN";
            case VK_ERROR_OUT_OF_POOL_MEMORY: return "VK_ERROR_OUT_OF_POOL_MEMORY";
            case VK_ERROR_INVALID_EXTERNAL_HANDLE: return "VK_ERROR_INVALID_EXTERNAL_HANDLE";
            case VK_ERROR_FRAGMENTATION: return "VK_ERROR_FRAGMENTATION";
            case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: return "VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS";
            case VK_PIPELINE_COMPILE_REQUIRED: return "VK_PIPELINE_COMPILE_REQUIRED";
            case VK_ERROR_SURFACE_LOST_KHR: return "VK_ERROR_SURFACE_LOST_KHR";
            case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: return "VK_ERROR_NATIVE_WINDOW_IN_USE_KHR";
            case VK_SUBOPTIMAL_KHR: return "VK_SUBOPTIMAL_KHR";
            case VK_ERROR_OUT_OF_DATE_KHR: return "VK_ERROR_OUT_OF_DATE_KHR";
            default: return "Unknow Error";
        }
    }

    const char* VkRequestErrorCodeDescription(const int32 code)
    {
        switch(code)
        {
            case VK_NOT_READY:
                return "A fence or query has not yet completed";
                
            case VK_TIMEOUT:
                return "A wait operation has not completed in the specified time";
                
            case VK_EVENT_SET:
                return "An event is signaled";
                
            case VK_EVENT_RESET:
                return "An event is unsignaled";
                
            case VK_INCOMPLETE:
                return "A return array was too small for the result";
                
            case VK_ERROR_OUT_OF_HOST_MEMORY:
                return "A host memory allocation has failed";
                
            case VK_ERROR_OUT_OF_DEVICE_MEMORY:
                return "A device memory allocation has failed";
                
            case VK_ERROR_INITIALIZATION_FAILED:
                return "Initialization of an object could not be completed for implementation-specific reasons";
                
            case VK_ERROR_DEVICE_LOST:
                return "The logical or physical device has been lost";
                
            case VK_ERROR_MEMORY_MAP_FAILED:
                return "Mapping of a memory object has failed";
                
            case VK_ERROR_LAYER_NOT_PRESENT:
                return "A requested layer is not present or could not be loaded";
                
            case VK_ERROR_EXTENSION_NOT_PRESENT:
                return "A requested extension is not supported";
                
            case VK_ERROR_FEATURE_NOT_PRESENT:
                return "A requested feature is not supported";
                
            case VK_ERROR_INCOMPATIBLE_DRIVER:
                return "The requested version of Vulkan is not supported by the driver or is otherwise incompatible";
                
            case VK_ERROR_TOO_MANY_OBJECTS:
                return "Too many objects of the type have already been created";
                
            case VK_ERROR_FORMAT_NOT_SUPPORTED:
                return "A requested format is not supported on this device";
                
            case VK_ERROR_FRAGMENTED_POOL:
                return "A pool allocation has failed due to fragmentation of the pool's memory";
                
            case VK_ERROR_UNKNOWN:
                return "An unknown error has occurred; either the application has provided invalid input, or an implementation failure has occurred";
                
            case VK_ERROR_OUT_OF_POOL_MEMORY:
                return "A pool memory allocation has failed";
                
            case VK_ERROR_INVALID_EXTERNAL_HANDLE:
                return "An external handle is not a valid handle of the specified type";
                
            case VK_ERROR_FRAGMENTATION:
                return "A descriptor pool creation has failed due to fragmentation";
                
            case VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS:
                return "A buffer creation or memory allocation failed because the requested address is not available";
                
            case VK_PIPELINE_COMPILE_REQUIRED:
                return "A requested pipeline creation would have required compilation, but the application requested compilation to not be performed";
                
            case VK_ERROR_SURFACE_LOST_KHR:
                return "A surface is no longer available";
                
            case VK_ERROR_NATIVE_WINDOW_IN_USE_KHR:
                return "The requested window is already in use by Vulkan or another API in a manner which prevents it from being used again";
                
            case VK_SUBOPTIMAL_KHR:
                return "A swapchain no longer matches the surface properties exactly, but can still be used to present to the surface successfully";
                
            case VK_ERROR_OUT_OF_DATE_KHR:
                return "A surface has changed in such a way that it is no longer compatible with the swapchain";
                
            default: return "Unknow Error";
        }
    }

    VulkanError::VulkanError(const int32 hr, 
        const string_view func, 
        const string_view file, 
        const int32 line) noexcept
        : Error{hr, func, file, line}
    {
    }

    string VulkanError::ToString() const
    {
        return format("{} failed in {}, line {}:\n{}\n{}",
            funcName, fileName, lineNum, VkRequestErrorCodeToString(hrCode), VkRequestErrorCodeDescription(hrCode));
    }
}