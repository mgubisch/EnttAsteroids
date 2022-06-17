#include "Factories.h"

#include "../components/Transform.h"
#include "../components/Velocity.h"
#include "../components/Sprite.h"
#include "../components/Lifetime.h"
#include "../components/SpriteAnim.h"


entt::entity create_asteroid(entt::registry& entity_reg, const float p_x, const float p_y, const float rotation, const float v_forward, const std::string& tex_name)
{
	const auto e = entity_reg.create();

	entity_reg.emplace<Transform>(e, p_x, p_y, rotation);
	entity_reg.emplace<Velocity>(e, v_forward, 0.0f);
	entity_reg.emplace<Sprite>(e, 32, 32, tex_name);

	return e;
}

entt::entity create_player(entt::registry& entity_reg, const float p_x, const float p_y, const std::vector<std::string>& tex_names)
{
	const auto e = entity_reg.create();

	entity_reg.emplace<Transform>(e, p_x, p_y);
	entity_reg.emplace<Velocity>(e, 0.0f, 0.0f);
	entity_reg.emplace<SpriteAnim>(e, tex_names, 24.0f);
	entity_reg.emplace<Sprite>(e, 64, 64, tex_names[0]);

	return e;

}

entt::entity create_laser(entt::registry& entity_reg, glm::vec2 pos, const float rotation, const float v_forward, const float lifetime, const std::string& tex_name)
{
	const auto e = entity_reg.create();

	entity_reg.emplace<Transform>(e, pos.x, pos.y, rotation);
	entity_reg.emplace<Velocity>(e, v_forward, 0.0f);
	entity_reg.emplace<Sprite>(e, 16, 16, tex_name);
	entity_reg.emplace<Lifetime>(e, lifetime);

	return e;
}
