#pragma once

#include <entt/entity/registry.hpp>

/// <summary>
/// system handling timed object lifetime
/// </summary>
class LifetimeSystem final
{
public:
	/// <summary>
	/// default c'tor
	/// </summary>
	LifetimeSystem() noexcept = default;

	/// <summary>
	/// defalt d'tor
	/// </summary>
	~LifetimeSystem() noexcept = default;

	void update(const float time, entt::registry& registry) noexcept;
};

