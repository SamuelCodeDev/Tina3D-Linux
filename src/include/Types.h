#ifndef TYPES_H
#define TYPES_H

#include <cstdint>
#include <string>
#include <string_view>

namespace Tina
{
    using int8 = std::int8_t;
    using int16 = std::int16_t;
    using int32 = std::int32_t;
    using int64 = std::int64_t;

    using uint8 = std::uint8_t;
    using uint16 = std::uint16_t;
    using uint32 = std::uint32_t;
    using uint64 = std::uint64_t;

    using string = std::string;
	using string_view = std::string_view;

    union Rect
	{
		struct
		{
			int32 left;
			int32 top;
			int32 right;
			int32 bottom;
		};

		struct
		{
			int32 x1;
			int32 y1;
			int32 x2;
			int32 y2;
		};

		int32 coord[4];
	};

	struct ViewPort
	{
		float TopLeftX;
		float TopLeftY;
		float Width;
		float Height;
		float MinDepth;
		float MaxDepth;
	};
}

#endif