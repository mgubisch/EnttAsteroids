#pragma once

#include <entt/entity/registry.hpp>
#include <SDL2/SDL_render.h>

#include <map>
#include <string>

class RenderSystem final
{
public:

	/// <summary>
	/// default c'tor
	/// </summary>
	RenderSystem() noexcept = default;

	/// <summary>
	/// default d'tor
	/// </summary>
	~RenderSystem() noexcept;

	/// <summary>
	/// Method to draw the sprites
	/// </summary>
	/// <param name="renderer">the sdl renderer to draw on</param>
	/// <param name="registry">the entity registry to get the sprites</param>
	void render_sprites(SDL_Renderer* renderer, entt::registry& registry);

	/// <summary>
	/// Returns an SDL texture corresponding to the given filename
	/// If the texture was already loaded the existing one is returned, otherwise the file is loaded and a new texture is created
	/// </summary>
	/// <param name="filename">path to texture file</param>
	/// <returns>ptr to the sdl texture created from given file</returns>
	[[nodiscard]] SDL_Texture* load_texture(SDL_Renderer* renderer, const std::string filename);

private:
	std::map<std::string, SDL_Texture*> m_textures;
};

