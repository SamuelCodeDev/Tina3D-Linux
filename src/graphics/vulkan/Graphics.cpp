#include "Graphics.h"
#include "Error.h"

namespace Tina
{
    Graphics::Graphics() noexcept : instance{}
    {
    }

    Graphics::~Graphics() noexcept
    {
        vkDestroyInstance(instance, nullptr);
    }

    void Graphics::Initialize(Window * window)
    {
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pNext = nullptr;
        appInfo.pApplicationName = window->Title().c_str();
        appInfo.applicationVersion = 1;
        appInfo.pEngineName = window->Title().c_str();
        appInfo.engineVersion = 1;
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo instInfo{};
        instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        instInfo.pNext = nullptr;
        instInfo.flags = 0;
        instInfo.pApplicationInfo = &appInfo;
        instInfo.enabledLayerCount = 0;
        instInfo.ppEnabledLayerNames = nullptr;
        instInfo.enabledExtensionCount = 0;
        instInfo.ppEnabledExtensionNames = nullptr;

        ThrowIfFailed(vkCreateInstance(&instInfo, nullptr, &instance));
    }
}