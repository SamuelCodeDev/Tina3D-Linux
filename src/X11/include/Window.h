#ifndef WINDOW_H
#define WINDOW_H

#include "Types.h"

namespace Tina
{
	enum WindowModes { FULLSCREEN, WINDOWED, BORDERLESS };

	class WindowDesc
	{
	protected:
		int32  windowWidth;
		int32  windowHeight;
		int32  windowStyle;
		int32  windowMode;
		float  windowCenterX;
		float  windowCenterY;
		float  windowPosX;
		float  windowPosY;
		string windowTitle;

	public:
		int32 Width() const noexcept;
		int32 Height() const noexcept;

		void Title(const string_view title) noexcept;

		int32 Mode() const noexcept;
		float CenterX() const noexcept;
		float CenterY() const noexcept;
		constexpr float AspectRatio() const noexcept;
		string Title() const noexcept;
	};

	inline int32 WindowDesc::Width() const noexcept
	{ return windowWidth; }

	inline int32 WindowDesc::Height() const noexcept
	{ return windowHeight; }

	inline void WindowDesc::Title(const string_view title) noexcept
	{ windowTitle = title; }

	inline int32 WindowDesc::Mode() const noexcept
	{ return windowMode; }

	inline float WindowDesc::CenterX() const noexcept
	{ return windowCenterX; }

	inline float WindowDesc::CenterY() const noexcept
	{ return windowCenterY; }

	inline constexpr float WindowDesc::AspectRatio() const noexcept
	{ return windowWidth / static_cast<float>(windowHeight); }

	inline string WindowDesc::Title() const noexcept
	{ return windowTitle; }
}

#include <X11/Xlib.h>

namespace Tina
{
	class Window final : public WindowDesc
	{
	private:
		Display* display;
		::Window window;
		Screen* screen;
		int32 screenNum;

	public:
		Window() noexcept;
		~Window() noexcept;

		Display* GetDisplay() const noexcept;
		::Window GetWindow() const noexcept;
		void Size(const int32 width, const int32 height) noexcept;
		void Close() const noexcept;

		bool Create();
	};

	inline Display* Window::GetDisplay() const noexcept
	{ return display; }

	inline ::Window Window::GetWindow() const noexcept
	{ return window; }

	inline void Window::Close() const noexcept
	{ XKillClient(display, window); }
}

#endif