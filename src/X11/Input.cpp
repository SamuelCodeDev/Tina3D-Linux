#include "Input.h"

namespace Tina
{
    bool Input::CheckKeyPress(const uint64 vkcode) const noexcept 
	{
		char keysReturn[32] {};
		XQueryKeymap(display, keysReturn);
		KeyCode kc2 = XKeysymToKeycode(display, vkcode);
		return !!(keysReturn[kc2 >> 3] & (1 << (kc2 & 7)));
	}
}