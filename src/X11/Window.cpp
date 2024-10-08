#include "Window.h"
#include "X11Error.h"
#include <X11/Xutil.h>

namespace Tina
{
	Window::Window() noexcept
	{
		display = XOpenDisplay(nullptr);
		screenNum = DefaultScreen(display);
		screen = XDefaultScreenOfDisplay(display);
		windowWidth = screen->width;
		windowHeight = screen->height;
		windowTitle = string("Window Game");
		windowPosX = 0;
		windowPosY = 0;
		windowCenterX = windowWidth / 2.0f;
		windowCenterY = windowHeight / 2.0f;
	}

	Window::~Window() noexcept
	{
		XUnmapWindow(display, window);
		XDestroyWindow(display, window);
		XCloseDisplay(display);
	}

	void Window::Size(const int32 width, const int32 height) noexcept
	{
		windowWidth = width;
		windowHeight = height;

		windowCenterX = windowWidth / 2.0f;
		windowCenterY = windowHeight / 2.0f;

		windowPosX = (screen->width - windowWidth) / 2.0f;
		windowPosY = (screen->height - windowHeight) / 2.0f;
	}

	bool Window::Create()
	{
		if(!display)
			return false;

		window = XCreateSimpleWindow(
			display, 
			RootWindow(display, screenNum), 
			int32(windowPosX), int32(windowPosY), 
			windowWidth, windowHeight,
			1,
			BlackPixel(display, screenNum),
			WhitePixel(display, screenNum)
		);
		XStoreName(display, window, windowTitle.c_str());
		XMapWindow(display, window);
		XMoveWindow(display, window, windowPosX, windowPosY);

		// Disable the resizing
		{
			XSizeHints hints;
			hints.flags = PMinSize | PMaxSize;
			hints.min_width = hints.max_width = windowWidth;
			hints.min_height = hints.max_height = windowHeight;
			XSetNormalHints(display, window, &hints);
		}

		constexpr auto eventMask = KeyReleaseMask | KeyPressMask;
		XSelectInput(display, window, eventMask);

		return true;
	}
}