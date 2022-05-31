#pragma once
#include "game.h"
class game_client
{
	game& game;


public:
	game_client(::game& game)
		: game(game)
	{
	}

	void go()
	{
		game.play();
	}
};

