#pragma once
#include "abstract_takegame_player.h"
class human_player: public abstract_takegame_player
{
public:
	human_player(const std::string& name)
		: abstract_takegame_player(name)
	{
	}


	int do_move(const int& stones) const override
	{
		int move;
		print("Es gibt " + std::to_string(stones) + " Steine. Bitte nehmen Sie 1,2 oder 3!");
		std::cin >> move;
		return move;
	}
};

