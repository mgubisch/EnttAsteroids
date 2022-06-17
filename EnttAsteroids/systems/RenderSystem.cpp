#include "RenderSystem.h"

#include "../components/Sprite.h"
#include "../components/Transform.h"
#include "../util/Log.h"

#include <SDL2/SDL_image.h>
#include "Math.h"


RenderSystem::~RenderSystem()
{
	for (auto it : m_textures)
	{
		SDL_DestroyTexture(it.second);
	}
}

void RenderSystem::render_sprites(SDL_Renderer* renderer, entt::registry& registry)
{
	auto sprite_view = registry.view<Sprite, Transform>();

	sprite_view.each([&](const auto& sprite, const auto& transform) {

		const SDL_Rect rect = 
		{ //rectangle should be centered around the position
		  static_cast<int32_t>(transform.m_position.x - sprite.m_width / 2), 
		  static_cast<int32_t>(transform.m_position.y - sprite.m_height / 2), 
		  //set width and height of the sprite
		  sprite.m_width, sprite.m_height };

		if (!sprite.m_texture.empty()) //draw with texture
		{
			SDL_Texture* tex = load_texture(renderer, sprite.m_texture);
			SDL_RenderCopyEx(renderer, tex, nullptr, &rect, -glm::degrees(transform.m_rotation), nullptr, SDL_FLIP_NONE);
		}
		else //draw with color
		{
			SDL_SetRenderDrawColor(renderer, sprite.m_color.r, sprite.m_color.b, sprite.m_color.b, sprite.m_color.a);
			SDL_RenderFillRect(renderer, &rect);
		}		
		});
}

SDL_Texture* RenderSystem::load_texture(SDL_Renderer* renderer, const std::string filename)
{
	SDL_Texture* tex = nullptr;

	auto it = m_textures.find(filename);
	if (it != m_textures.end())
	{
		tex = it->second;
	}
	else
	{
		//create texture from surface
		tex = IMG_LoadTexture(renderer, filename.c_str());
		if (!tex)
		{
			throw_sdl2_exception("Failed to create texture from surface for file: " + filename);
		}

		m_textures.emplace(filename, tex);
	}

	return tex;
}
