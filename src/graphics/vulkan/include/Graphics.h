#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Types.h"
#include "Window.h"
#include <vulkan/vulkan.h>

namespace Tina
{
    class Graphics final
	{
	private:
        VkInstance instance;

	public:
		Graphics() noexcept;
		~Graphics() noexcept;

		void Initialize(Window* window);
		VkInstance Instance() const noexcept;
	};

    inline VkInstance Graphics::Instance() const noexcept
    { return instance; }
}

#endif