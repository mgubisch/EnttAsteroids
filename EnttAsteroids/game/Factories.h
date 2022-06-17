#pragma once

#include "../util/Math.h"

#include <entt/entity/registry.hpp>

#include <SDL2/SDL_render.h>

/// <summary>
/// creates a new asteroid instance
/// sprite width and height are determined from texture size
/// </summary>
/// <param name="entity_reg">the entity registry to use</param>
/// <param name="p_x">initial x position</param>
/// <param name="p_y">initial y position</param>
/// <param name="v_forward">initial speed</param>
/// <param name="tex_name">name of asteroid texture</param>
/// <returns>entity identifier</returns>
[[maybe_unused]] entt::entity create_asteroid(entt::registry& entity_reg, const float p_x, const float p_y, const float rotation, const float v_forward, const std::string& tex_name);

/// <summary>
/// creates an entity for the player
/// </summary>
/// <param name="entity_reg">entity registry to use</param>
/// <param name="p_x">initial x position</param>
/// <param name="p_y">initial y position</param>
/// <param name="tex_names">array of player ship textures to animate</param>
/// <returns>entity identifier</returns>
[[maybe_unused]] entt::entity create_player(entt::registry& entity_reg, const float p_x, const float p_y, const std::vector<std::string>& tex_names);

/// <summary>
/// creates and laser bullet entity
/// </summary>
/// <param name="entity_reg">entity registry to use</param>
/// <param name="pos">initial screen position</param>
/// <param name="rotation">initial rotation</param>
/// <param name="v_forward">forward velocity</param>
/// <param name="lifetime">the lifetime of the bullet</param>
/// <param name="tex_name">name of laser texture</param>
/// <returns>entity identifier</returns>
[[maybe_unused]]  entt::entity create_laser(entt::registry& entity_reg, glm::vec2 pos, const float rotation, const float v_forward, const float lifetime, const std::string& tex_name);