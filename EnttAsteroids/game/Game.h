#pragma once

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

#include <entt/entt.hpp>

#include "../systems/MoveSystem.h"
#include "../systems/RenderSystem.h"
#include "../systems/PlayerSystem.h"
#include "../systems/LifetimeSystem.h"
#include "../systems/SpriteAnimationSystem.h"

#include "../events/KeyDown.h"
#include "../events/KeyUp.h"
#include "../events/PlayerCreated.h"

/// <summary>
/// This class will manage game loop, game data and application instance
/// </summary>
class Game
{
public:
	Game(int32_t window_w, int32_t window_h);

	~Game() noexcept;

	void run_loop() noexcept;

	//event sinks

	/// <summary>
	/// called when a key is pressed
	/// </summary>
	/// <param name="key_down">key down event holding the keycode</param>
	void on_key_down(const KeyDown& key_down) noexcept;

private:
	void process_input()  noexcept;

	void update_game(const float dT)  noexcept;

	void generate_output()  noexcept;

	void init_game_data()  noexcept;

	int32_t m_window_width;
	int32_t m_window_height;

	SDL_Window* m_window = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	entt::registry		m_entity_registry;
	entt::dispatcher	m_event_dispatcher;

	MoveSystem				m_move_system;
	RenderSystem			m_render_system;
	PlayerSystem			m_player_system;
	LifetimeSystem			m_lifetime_system;
	SpriteAnimationSystem	m_sprite_animation_system;

	bool m_is_running = false;

	entt::entity m_player;
};

