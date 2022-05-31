#include "AbstractGameTest.h"




TEST_F(AbstractGameTest, play_success)
{


	EXPECT_CALL(game_player_mock, do_move(_)).WillOnce([this](DummyBoard d)
		{
			object_under_test.game_over = true;
			return DummyMove{};
		});

	EXPECT_CALL(writer_mock, write(Eq("MockPlayer hat verloren")));

	object_under_test.play();
}

TEST_F(AbstractGameTest, play_mogeln)
{

	object_under_test.is_move_valid = false;

	EXPECT_CALL(game_player_mock, do_move(_)).WillRepeatedly([this](DummyBoard d)
		{
			object_under_test.game_over = true;
			return DummyMove{};
		});

	EXPECT_CALL(writer_mock, write(Eq("Ungueltiger Zug!"))).WillOnce([this](std::string s) { object_under_test.is_move_valid = true; });
	EXPECT_CALL(writer_mock, write(Eq("MockPlayer hat verloren")));

	object_under_test.play();
}

