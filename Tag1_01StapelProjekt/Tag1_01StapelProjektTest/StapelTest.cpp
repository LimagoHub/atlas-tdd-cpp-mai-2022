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