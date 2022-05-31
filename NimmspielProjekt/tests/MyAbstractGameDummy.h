#pragma once
#include "../source/AbstractGame.h"
#include "../source/writer.h"
#include "DummyClassesForTest.h"


class MyAbstractGameDummy : public AbstractGame<DummyBoard, DummyMove>
{
public:
	bool game_over{ false };
	bool is_move_valid{ true };


	MyAbstractGameDummy(Writer& w)
		: AbstractGame<DummyBoard, DummyMove>(w)
	{
	}


protected:
	bool is_gameover() const override { return game_over; }
	bool is_valid() const override { return is_move_valid; }
	void update_game_state() override
	{
		// Ok
	};
};
