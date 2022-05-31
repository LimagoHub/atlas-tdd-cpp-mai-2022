#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "DummyClassesForTest.h"
#include "../source/player.h"




class Mockplayer : public player<DummyBoard, DummyMove>
{
public:
	MOCK_METHOD(std::string, get_name, (), (const, override));
	MOCK_METHOD(DummyMove, do_move, (const DummyBoard& scene), (const, override));
};
