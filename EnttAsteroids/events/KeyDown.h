#pragma once

#include <cstdint>

struct KeyDown final
{
	/// <summary>
	/// Argument constructor
	/// </summary>
	/// <param name="key_code">SDL_keycode</param>
	inline KeyDown(int32_t key_code) noexcept
		: m_keycode(key_code)
	{
	}

	/// <summary>
	/// stores the sdl keycode
	/// defaults to -1
	/// </summary>
	int32_t m_keycode = -1;
};
