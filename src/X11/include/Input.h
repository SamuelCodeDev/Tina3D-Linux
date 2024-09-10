#ifndef INPUT_H
#define INPUT_H

#include "Types.h"
#include <X11/Xlib.h>

namespace Tina
{
	class Input final
	{
	private:
		Display * display;
		XEvent * event;

	public:
		void SetDisplay(Display * display) noexcept;
		void SetEvent(XEvent * event) noexcept;

		bool KeyDown(const uint64 vkcode) const noexcept;
		bool CheckKeyPress(const uint64 vkcode) const noexcept;
	};

	inline void Input::SetDisplay(Display * display) noexcept
	{ this->display = display; }

	inline void Input::SetEvent(XEvent * event) noexcept
	{ this->event = event; }
	
	inline bool Input::KeyDown(const uint64 vkcode) const noexcept
	{ return (event->type == KeyPress) ? XLookupKeysym(&event->xkey, 0) == vkcode : false; }
}

#endif