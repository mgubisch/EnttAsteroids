#pragma once

#include <entt/entity/registry.hpp>

class SpriteAnimationSystem final
{
public:
	/// <summary>
	/// default c'tor
	/// </summary>
	SpriteAnimationSystem() noexcept = default;

	/// <summary>
	/// default d'tor
	/// </summary>
	~SpriteAnimationSystem() noexcept = default;

	/// <summary>
	/// updates the texture of the sprite bound to this entity based on SpriteAnim state
	/// </summary>
	/// <param name="time">time elapsed since last frame</param>
	/// <param name="registry">the entity regitsy to work on</param>
	void update(const float time, entt::registry& registry) noexcept;
};