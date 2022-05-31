#pragma once
#include <iostream>
#include "player.h"
template<class BOARD, class MOVE>
class abstract_player : public player<BOARD,MOVE>
{
	std::string name;


public:
	abstract_player(const std::string& name = "Dummy")
		: name(name)
	{
	}


	std::string get_name() const override
	{
		return name;
	}

protected:
	void print(const std::string& message) const
	{
		std::cout << message << std::endl;
	}
};