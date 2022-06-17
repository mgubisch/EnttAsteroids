#pragma once

#include <vector>
#include <string>


class SpriteAnim final
{
public:
	/// <summary>
	/// argument c'tor
	/// </summary>
	/// <param name="textures">array of texture names in animation order</param>
	/// <param name="fps">animation speed in frames per second</params>
	/// <param name="starte_frame">the index of the first texture in the animation, default value is 0</params>
	SpriteAnim(const std::vector<std::string>& textures, float fps, float start_frame = 0) noexcept;

	/// <summary>
	/// Move constructor
	/// </summary>
	SpriteAnim(SpriteAnim&&) noexcept;

	/// <summary>
	/// default d'tor
	/// </summary>
	~SpriteAnim() noexcept = default;

	/// <summary>
	/// Move Assignment operator
	/// </summary>
	SpriteAnim& operator=(SpriteAnim&&) noexcept;

public:
	/// <summary>
	/// stores the names of the textures for the animation
	/// </summary>
	std::vector<std::string> m_anim_textures;

	/// <summary>
	/// the index for the currently used texture
	/// </summary>
	float m_current_frame;

	/// <summary>
	/// stores the animation speed in frames per second
	/// </summary>
	float m_anim_fps;
};