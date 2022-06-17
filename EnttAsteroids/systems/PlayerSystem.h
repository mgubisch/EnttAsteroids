#pragma once

#include <entt/entt.hpp>

#include "../events/KeyDown.h"
#include "../events/KeyUp.h"
#include "../events/PlayerCreated.h"

class PlayerSystem final
{
public:
	PlayerSystem() noexcept = default;

	~PlayerSystem() noexcept = default;

	/// <summary>
	/// update player velocity based on key events
	/// </summary>
	/// <param name="time">the time elapsed since last frame</param>
	/// <param name="registry">the entity registry to work on</param>
	void update(const float time, entt::registry& registry) noexcept;


	//event sinks

	/// <summary>
	/// called if key pressed
	/// </summary>
	/// <param name="key_down">key event storing keycode</param>
	void on_key_down(const KeyDown& key_down) noexcept;

	/// <summary>
	/// called if key is released
	/// </summary>
	/// <param name="key_down">key event storing keycode</param>
	void on_key_up(const KeyUp& key_down) noexcept;

	/// <summary>
	/// called if player is created
	/// </summary>
	/// <param name="player_id">id of player entity</param>
	void on_player_created(const PlayerCreated& player_created);

private:
	entt::entity m_player_entity = entt::null;

	float m_forward_speedd = 0;
	float m_angular_speed = 0;

	bool m_fire = false;
	float m_laser_cooldown = 0.0f;
};

