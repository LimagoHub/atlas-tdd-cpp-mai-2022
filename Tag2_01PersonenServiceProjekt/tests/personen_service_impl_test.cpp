#include <stdexcept>
#include "personen_service_impl_test.h"
using namespace testing;
TEST_F(personen_service_impl_test, speichern_vorname_zu_kurz_throws_personen_service_exception_and_errormessage)
{
	try
	{
		// Arrange
		person p{ "","J","Doe" };
		// Act

		// Assertion
		object_under_test.speichern(p);
		FAIL() << "Exception expected!";
		
	} catch (personen_service_execption &ex)
	{
		EXPECT_STREQ("Vorname zu kurz!", ex.what());
	}
}
TEST_F(personen_service_impl_test, speichern_nachname_zu_kurz_throws_personen_service_exception_and_errormessage)
{
    try
    {
        // Arrange
        person p{ "","John","D" };
        // Act

        // Assertion
        object_under_test.speichern(p);
        FAIL() << "Exception expected!";

    } catch (personen_service_execption &ex)
    {
        EXPECT_STREQ("Nachname zu kurz!", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern_Antipath_throws_personen_service_exception_and_errormessage)
{
    try
    {
        // Arrange
        person p{ "","John","Doe" };
        // Act

        EXPECT_CALL(blacklist_serviceMock, is_blacklisted(p)).WillRepeatedly(Return(true));

        // Assertion
        object_under_test.speichern(p);
        FAIL() << "Exception expected!";

    } catch (personen_service_execption &ex)
    {
        EXPECT_STREQ("Person ist Antipath!", ex.what());
    }
}

TEST_F(personen_service_impl_test, speichern_unexpected_exception_in_underlying_servie_throws_personen_service_exception_and_errormessage)
{
    try
    {
        // Arrange
        person p{ "","John","Doe" };
        // Act
        EXPECT_CALL(blacklist_serviceMock, is_blacklisted(_)).WillOnce(Return(false));
        ON_CALL(repoMock, saveOrUpdate(_)).WillByDefault(Throw(std::out_of_range{"upps"}));
        // Assertion
        object_under_test.speichern(p);
        FAIL() << "Exception expected!";

    } catch (personen_service_execption &ex)
    {
        EXPECT_STREQ("Unerwarteter Fehler im Reposervice", ex.what());
    }
}
TEST_F(personen_service_impl_test, speichern_happy_day_person_is_passed_to_repo)
{

        InSequence s;
        // Arrange
        person validPerson{ "","John","Doe" };
        person expectedPerson{ "1","John","Doe" };

        EXPECT_CALL(blacklist_serviceMock, is_blacklisted(_)).WillOnce(Return(false));
        EXPECT_CALL(repoMock, saveOrUpdate(expectedPerson));
        // Act

        // Assertion
        EXPECT_NO_THROW(object_under_test.speichern(validPerson));
        EXPECT_EQ("1", validPerson.get_id());
}
TEST_F(personen_service_impl_test, speichern_overloaded_happy_day_person_is_passed_to_repo)
{
    person result;


    //EXPECT_CALL(blacklist_serviceMock, is_blacklisted(_)).WillOnce(Return(false));
    EXPECT_CALL(blacklist_serviceMock, is_blacklisted(_)).WillOnce([this](const person &p){
        return false;});
    EXPECT_CALL(repoMock, saveOrUpdate(_)).WillOnce(DoAll(SaveArg<0>(&result)));
    // Act

    // Assertion
    EXPECT_NO_THROW(object_under_test.speichern("Ulli","Schmitt"));
    EXPECT_EQ("1", result.get_id());
}