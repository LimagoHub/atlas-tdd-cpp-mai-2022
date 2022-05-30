#include "CalcClientTest.h"

using namespace testing;
TEST_F(CalcClientTest, run_1)
{

	InSequence s;
	//ON_CALL(calculatorMock, add(_, _)).WillByDefault((Return(4711.0)));
	
	EXPECT_CALL(calculatorMock, add(3.0, 4.0)).Times(1).WillOnce(Return(42.0));
	EXPECT_CALL(calculatorMock, add(3.0, 5.0)).Times(1).WillOnce(Return(4777.0));
	object_under_test.run();
}