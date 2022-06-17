#pragma once

#include <cstdint>

struct KeyUp final
{
	/// <summary>
	/// argument constructor
	/// </summary>
	/// <param name="key_kode">SDL key code</param>
	inline KeyUp(int32_t key_kode) noexcept
		: m_keycode{ key_kode }
	{
	}

	/// <summary>
	/// stores the sdl keycode
	/// defaults to -1
	/// </summary>
	int32_t m_keycode = -1;
};