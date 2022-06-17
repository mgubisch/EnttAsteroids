#pragma once

#include <entt/entity/registry.hpp>

#include "Math.h"

class MoveSystem final
{
public:
	/// <summary>
	/// argument c'tor
	/// </summary>
	/// <param name="width">screen width</param>
	/// <param name="height">screen height</param>
	/// <returns></returns>
	MoveSystem(int32_t width, int32_t height) noexcept;

	/// <summary>
	/// default d'tor
	/// </summary>
	~MoveSystem() noexcept = default;

	/// <summary>
	/// update entity position based on velocity and previous position
	/// </summary>
	/// <param name="time">the time elapsed since last frame</param>
	/// <param name="registry">the entity registry to work on</param>
	void update(const float time, entt::registry& registry) noexcept;

private:
	int32_t m_window_width;
	int32_t m_window_height;
};

