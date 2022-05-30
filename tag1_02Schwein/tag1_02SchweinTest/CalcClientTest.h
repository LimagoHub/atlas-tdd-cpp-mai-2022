#pragma once

#include <gtest/gtest.h>
#include "../tag1_02Schwein/Calculator.h"
#include "../tag1_02Schwein/CalcClient.h"
#include "MockCalculator.h"
class CalcClientTest : public testing::Test
{
protected:
	MockCalculator calculatorMock;
	CalcClient object_under_test{ calculatorMock};
};

