#include "MoveSystem.h"

#include "../components/Velocity.h"
#include "../components/Transform.h"

#include "../util/Math.h"

MoveSystem::MoveSystem(int32_t width, int32_t height) noexcept
	:	m_window_width{width},
		m_window_height{height}
{
}

void MoveSystem::update(const float time, entt::registry& registry) noexcept
{
	auto view = registry.view<Velocity, Transform>();

	view.each([&](auto& velocity, auto& transform) {

		//update rotation
		transform.m_rotation += velocity.m_angular_speed * time;
		
		//update position
		transform.m_position += get_forward_vector(transform.m_rotation) * static_cast<float>(velocity.m_forward_speed) * static_cast<float>(time);

		//screen wrapping
		if (transform.m_position.x <0.0f)
		{
			transform.m_position.x = static_cast<float>(m_window_width);
		}
		else if (transform.m_position.x > m_window_width)
		{
			transform.m_position.x = 0.0;
		}

		if (transform.m_position.y < 0.0)
		{
			transform.m_position.y = static_cast<float>(m_window_height);
		}
		else if (transform.m_position.y > m_window_height)
		{
			transform.m_position.y = 0.0;
		}
		});
}
