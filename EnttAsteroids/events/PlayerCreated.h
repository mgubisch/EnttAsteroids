#pragma once

#include <cstdint>

#include <entt/entity/registry.hpp>

struct PlayerCreated final
{
 	/// <summary>
 	/// argument constructor
 	/// </summary>
 	/// <param name="player_id">the id of the player entity</param>
	inline PlayerCreated(entt::entity player_id) noexcept
		: m_player_entity{ player_id }
	{
	}

	/// <summary>
	/// stores the player entity id
	/// defaults to entt::null which marks an invalid id
	/// </summary>
	entt::entity m_player_entity = entt::null;
};
