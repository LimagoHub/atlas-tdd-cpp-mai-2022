#include "StapelTest.h"


TEST_F(StapelTest, is_empty_leerer_stapel_returns_true) {// 1. Name der Testmethode, 2. Testfall 3 erwartung
	// Arrange


	// Action
	

	// Assertion
	EXPECT_TRUE(object_under_test.is_empty());
}

TEST_F(StapelTest, is_empty_nicht_leerer_stapel_returns_false) {// 1. Name der Testmethode, 2. Testfall 3 erwartung
	// Arrange
	object_under_test.push(1);

	// Action


	// Assertion
	EXPECT_FALSE(object_under_test.is_empty());
}

TEST_F(StapelTest, is_empty_empty_again_returns_true)
{
	// Arrange

	object_under_test.push(1);
	object_under_test.pop();


	// Act
	bool ergebnis = object_under_test.is_empty();

	// Assertion
	EXPECT_TRUE(ergebnis);
}

TEST_F(StapelTest, push_fill_up_to_limit_no_exception_thrown)
{

	// Arrange
	for (int i = 0; i < 9; i++)
		object_under_test.push(1);


	// act + assertion
	EXPECT_NO_THROW(object_under_test.push(1));
}

TEST_F(StapelTest, push_overflow_throws_stapelexception)
{
	for (int i = 0; i < 10; i++)
		object_under_test.push(1);

	EXPECT_THROW(object_under_test.push(1), StapelException);
}

TEST_F(StapelTest, push_overflow_throws_stapelexception_variante2)
{
	try
	{
		// Arrange
		for (int i = 0; i < 10; i++)
			object_under_test.push(i);
		// Act
		object_under_test.push(1);
		FAIL() << "expected exception is not thrown";
	}
	catch (StapelException& ex)
	{
		EXPECT_STREQ("Overflow", ex.what());
	}
}