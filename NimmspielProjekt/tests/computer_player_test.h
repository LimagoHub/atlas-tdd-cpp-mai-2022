#pragma once
#include "gtest/gtest.h"
#include "../source/computer_player.h"
using namespace testing;

class computer_player_test: public Test
{
protected:
	computer_player object_under_test{"Fritz"};
};


class computer_player_parameter_test : public computer_player_test, public WithParamInterface<std::pair<int, int>>
{
public:
	

protected:
	int param;
	int result;

	void SetUp() override
	{
		std::tie<int, int>(param, result) = GetParam();
	}
};
