#include "SchweinTest.h"


TEST_F(SchweinTest, ctor_WrongNameElsa_throwsInvalid_argument_exception)
{
	try {
		// Act
		schwein object_under_test_lokal{ "Elsa" };
		FAIL() << "Upps";
	} catch (std::invalid_argument &ex)
	{
		EXPECT_STREQ("name ist nicht erlaubt", ex.what());
	}
	
	

}

TEST_F(SchweinTest, ctor_default_valid_initializion)
{
	EXPECT_EQ("nobody", object_under_test.get_name());
	EXPECT_EQ(10, object_under_test.get_gewicht());
	
}

TEST_F(SchweinTest, ctor_overloadWithValidName_valid_initializion)
{
	schwein object_under_test_lokal{ "Piggy" };
	EXPECT_EQ("Piggy", object_under_test_lokal.get_name());
	EXPECT_EQ(10, object_under_test_lokal.get_gewicht());

}

TEST_F(SchweinTest, set_name_WrongNameElsa_throwsInvalid_argument_exception)
{
	try {
		// Act
		object_under_test.set_name("Elsa");
		FAIL() << "Upps";
	}
	catch (std::invalid_argument& ex)
	{
		EXPECT_STREQ("name ist nicht erlaubt", ex.what());
	}



}
TEST_F(SchweinTest, set_name_HappyDay_Success)
{
	
		// Act
		object_under_test.set_name("Piggy");

		// Assertion
		EXPECT_EQ("Piggy", object_under_test.get_name());



}

TEST_F(SchweinTest, fressen_HappyDay_weightIncreased)
{

	// Act
	object_under_test.fressen();

	// Assertion
	EXPECT_EQ(11, object_under_test.get_gewicht());



}
