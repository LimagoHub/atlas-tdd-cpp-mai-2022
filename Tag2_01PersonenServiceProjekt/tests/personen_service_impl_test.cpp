#include "personen_service_impl_test.h"

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
