#pragma once
#include <vector>

#include "abstract_takegame_player.h"
class computer_player :
    public abstract_takegame_player
{
public:
	computer_player(const std::string& name)
		: abstract_takegame_player(name)
	{
	}


	int do_move(const int& stones) const override
	{
		std::vector<int> moves{ 3,1,1,2 };


		int move = moves[stones % 4];
		print("Computer nimmt " + std::to_string(move) + " Steine.");

		return move;
	}
};

