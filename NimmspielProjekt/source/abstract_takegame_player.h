#pragma once
#include <iostream>
#include "abstrcat_player.h"
class abstract_takegame_player: public abstract_player<int,int>
{
	


public:
	abstract_takegame_player(const std::string& name = "Dummy")
		: abstract_player<int, int>(name)
	{
	}


	

};

