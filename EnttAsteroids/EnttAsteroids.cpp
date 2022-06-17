// EnttAsteroids.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "game/Game.h"

#include <iostream>

int main()
{
    std::unique_ptr<Game> game = std::make_unique<Game>(1024, 768);

    game->run_loop();

    return 0;
}
