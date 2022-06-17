#pragma once

#include <SDL2/SDL_render.h>

#include <string>

/// <summary>
/// component describing a rectangle sprite for rendering
/// </summary>
class Sprite final
{
public:
	/// <summary>
	/// color rectangle constructor
	/// </summary>
	/// <param name="w">width in pixels</param>
	/// <param name="h">height in pixels</param>
	/// <param name="col">color of the sprite</param>
	Sprite(const int32_t w, const int32_t h, SDL_Colour col) noexcept;

	/// <summary>
	/// texture rectangle constructor
	/// </summary>
	/// <param name="w">width in pixels</param>
	/// <param name="h">height in pixels</param>
	/// <param name="tex">texture for the sprite</param>
	/// <returns></returns>
	Sprite(const int32_t w, const int32_t h, const std::string& tex) noexcept;

	/// <summary>
	/// move c'tor
	/// </summary>
	Sprite(Sprite&&) noexcept;

	/// <summary>
	/// default d'tor
	/// </summary>
	~Sprite() noexcept = default;

	/// <summary>
	/// move assignment operator
	/// </summary>
	Sprite& operator=(Sprite&&) noexcept;

public:

	/// <summary>
	/// stores the width of the sprite
	/// </summary>
	int32_t m_width;

	/// <summary>
	/// stores the height of the sprite
	/// </summary>
	int32_t m_height;

	/// <summary>
	/// stores the color of the sprite
	/// </summary>
	SDL_Colour m_color;

	/// <summary>
	/// stores the texture to use
	/// </summary>
	std::string m_texture;
};

