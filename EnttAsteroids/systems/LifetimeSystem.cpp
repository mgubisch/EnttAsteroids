#include "LifetimeSystem.h"

#include "../components/Lifetime.h"

void LifetimeSystem::update(const float time, entt::registry& registry) noexcept
{
	auto view = registry.view<Lifetime>();

	view.each([&](const auto entity, auto& lifetime) {
		lifetime.m_lifetime -= time;

		if (lifetime.m_lifetime < 0.0)
		{
			registry.destroy(entity);
		}

		});
}
