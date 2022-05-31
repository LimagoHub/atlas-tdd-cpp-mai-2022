#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "AbstractGame.h"
#include "writer.h"
class takegame_impl: public AbstractGame<int, int>
{
	
	

protected:
	bool is_gameover() const override
	{
		return board < 1 || get_players().empty();
	}

	bool is_valid() const override
	{
		return move >= 1 && move <= 3;
	}

	void update_game_state() override
	{
		board -= move;
	}


	void do_something() override
	{
		print(get_current_player()->get_name() + " ist am Zug");
	}
public:
	takegame_impl(Writer & w): AbstractGame<int, int>(w)
	{
		board = 23;
	}


	
};

