#include "Game.h"

#include "../util/Log.h"
#include "../util/Random.h"
#include "Factories.h"

#include <SDL2/SDL_image.h>

Game::Game(int32_t window_w, int32_t window_h)
	:	m_window_width{window_w},
		m_window_height{window_h},
		m_move_system{m_window_width, m_window_height},
		m_player{ entt::null }
{
	int32_t sdl_result = SDL_Init(SDL_INIT_VIDEO |SDL_INIT_EVENTS);

	if (sdl_result != 0)
	{
		throw_sdl2_exception("Unable to init SDL2");
	}

	m_window = SDL_CreateWindow("EnTT Asteroids", 100, 100, m_window_width, m_window_height, 0);
	if (!m_window)
	{
		throw_sdl2_exception("Unable to create window");
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_renderer)
	{
		throw_sdl2_exception("Unable to create renderer");
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		throw_sdl2_exception("Unable to init SDL_image");
	}

	LOG_INFO << "Initialization successful" << std::endl;

	//connecting events
	m_event_dispatcher.sink<KeyDown>().connect<&Game::on_key_down>(this);
	m_event_dispatcher.sink<KeyDown>().connect<&PlayerSystem::on_key_down>(m_player_system);
	m_event_dispatcher.sink<KeyUp>().connect<&PlayerSystem::on_key_up>(m_player_system);
	m_event_dispatcher.sink<PlayerCreated>().connect<&PlayerSystem::on_player_created>(m_player_system);

	//game loop can only run if init is successful
	m_is_running = true;
}

Game::~Game() noexcept
{
	IMG_Quit();
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void Game::run_loop()  noexcept
{
	//First we need to init our game data
	init_game_data();

	const constexpr double dt = 1000.0 / 60.0;

	// This is a fixed-step gameloop.
	// See https://gafferongames.com/post/fix_your_timestep/
	// For an explanation.
	double time = 0.0;
	double accumulator = 0.0;
	double current_time = SDL_GetTicks();
	double new_time = 0.0;
	double frame_time = 0.0;

    while (m_is_running)
    {
		new_time = SDL_GetTicks();
		frame_time = new_time - current_time;
		current_time = new_time;

		accumulator += frame_time;

		process_input();

		while (accumulator >= dt)
		{
			update_game(static_cast<float>(accumulator / 1000.0)); //convert time to seconds

			accumulator -= dt;
			time += dt;
		}
        
        generate_output();
    }
}

void Game::on_key_down(const KeyDown& key_down) noexcept
{
	if (key_down.m_keycode == SDLK_ESCAPE)
	{
		m_is_running = false;
	}
}

void Game::process_input() noexcept
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			m_is_running = false;
			break;
		case SDL_KEYDOWN:
			if (e.key.repeat == 0) //this is to avoid getting multiple keydown events if we hold the key
			{
				m_event_dispatcher.trigger(KeyDown{ e.key.keysym.sym });
			}
			break;
		case SDL_KEYUP:
			m_event_dispatcher.trigger(KeyUp{ e.key.keysym.sym });
			break;
		default:
			break;
		}
	}
}

void Game::update_game(const float dT) noexcept
{
	m_player_system.update(dT, m_entity_registry);
	m_lifetime_system.update(dT, m_entity_registry);
	m_sprite_animation_system.update(dT, m_entity_registry);
	m_move_system.update(dT, m_entity_registry);
}

void Game::generate_output() noexcept
{
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 255, 255);
	SDL_RenderClear(m_renderer);

	m_render_system.render_sprites(m_renderer, m_entity_registry);

	SDL_RenderPresent(m_renderer);
}

void Game::init_game_data() noexcept
{
	const constexpr int32_t num_asteroids = 20;

	for (int32_t i = 0; i < num_asteroids; i++)
	{
		auto p_x = random(0.f, static_cast<float>(m_window_width));
		auto p_y = random(0.f, static_cast<float>(m_window_height));
		auto v_forward = random(-20.0f, 20.0f);
		auto rotation = random(0.0f, 360.0f);

		create_asteroid(m_entity_registry, p_x, p_y, rotation, v_forward, "Assets/Asteroid.png");
	}

	std::vector<std::string> ship_textures = { "Assets/Ship.png", "Assets/ShipWithThrust.png" };
	m_player = create_player(m_entity_registry, m_window_width / 2.0f, m_window_height / 2.0f, ship_textures );
	m_event_dispatcher.trigger(PlayerCreated{ m_player });
}
