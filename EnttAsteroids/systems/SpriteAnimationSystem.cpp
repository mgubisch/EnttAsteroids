#include "SpriteAnimationSystem.h"

#include "../components/Sprite.h"
#include "../components/SpriteAnim.h"

void SpriteAnimationSystem::update(const float time, entt::registry& registry) noexcept
{
	auto view = registry.view<SpriteAnim, Sprite>();

	view.each([&](auto& spriteAnim, auto& sprite)
		{
			//only update if animation constains textures
			if (spriteAnim.m_anim_textures.size() > 0)
			{
				//update current frame index based on frame rate and elapsed time
				spriteAnim.m_current_frame += spriteAnim.m_anim_fps * time;

				//wrap current frame if neccesary
				while (spriteAnim.m_current_frame >= spriteAnim.m_anim_textures.size())
				{
					spriteAnim.m_current_frame -= spriteAnim.m_anim_textures.size();
				}

				//update texture for sprite
				sprite.m_texture = spriteAnim.m_anim_textures[static_cast<uint32_t>(spriteAnim.m_current_frame)];
			}
		});
}

