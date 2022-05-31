#pragma once

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "MyAbstractGameDummy.h"


#include "DummyClassesForTest.h"
#include "Mockplayer.h"
#include "Mockwriter.h"

using namespace testing;
class AbstractGameTest: public Test
{
protected:

	Mockwriter writer_mock;
	Mockplayer game_player_mock;
	MyAbstractGameDummy object_under_test{ writer_mock };


	void SetUp() override
	{
		object_under_test.add_player(&game_player_mock);
		EXPECT_CALL(game_player_mock, get_name()).Times(AnyNumber()).WillRepeatedly(Return("MockPlayer"));
	}
};

