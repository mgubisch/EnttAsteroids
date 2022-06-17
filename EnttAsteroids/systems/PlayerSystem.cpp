#include "PlayerSystem.h"

#include "../components/Velocity.h"
#include "../components/Transform.h"
#include "../game/Factories.h" //this looks smelly, maybe player system should life in game instead of systems?

#include "../util/Log.h"

#include <SDL2/SDL_keyboard.h>

void PlayerSystem::update(const float time, entt::registry& registry) noexcept
{
	if (registry.valid(m_player_entity))
	{
		auto& velocity = registry.get<Velocity>(m_player_entity);

		velocity.m_angular_speed = m_angular_speed;
		velocity.m_forward_speed = m_forward_speedd;

		if (m_fire && m_laser_cooldown <= 0.0f)
		{
			auto& pos = registry.get<Transform>(m_player_entity);			
			create_laser(registry, pos.m_position, glm::degrees(pos.m_rotation), 100.0, 5, "Assets/Laser.png");
			m_laser_cooldown = 1.0f;
		}

		//reset cooldown
		if (m_laser_cooldown >= 0.0f)
		{
			m_laser_cooldown -= time;
		}
	}
	else
	{
		LOG_WARNING << "Invalid player id" << std::endl;
	}
}

void PlayerSystem::on_key_down(const KeyDown& key_down) noexcept
{
	int32_t key = key_down.m_keycode;

	if (key == SDLK_UP || key == SDLK_w)
	{
		m_forward_speedd = 50;
	}
	
	if (key == SDLK_LEFT || key == SDLK_a)
	{
		m_angular_speed = glm::pi<float>();
	}
	else if (key == SDLK_RIGHT || key == SDLK_d)
	{
		m_angular_speed = -glm::pi<float>();
	}

	if (key == SDLK_SPACE)
	{
		m_fire = true;
	}
}

void PlayerSystem::on_key_up(const KeyUp& key_up) noexcept
{
	int32_t key = key_up.m_keycode;

	if (key == SDLK_UP || key == SDLK_w)
	{
		m_forward_speedd = 0;
	}
	if (key == SDLK_LEFT || key == SDLK_a)
	{
		m_angular_speed = 0.0f;
	}
	if (key == SDLK_RIGHT || key == SDLK_d)
	{
		m_angular_speed = 0.0f;
	}

	if (key == SDLK_SPACE)
	{
		m_fire = false;
	}
}

void PlayerSystem::on_player_created(const PlayerCreated& player_created)
{
	m_player_entity = player_created.m_player_entity;
}
