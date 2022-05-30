#pragma once
#include <gtest/gtest.h>
#include "../tag1_02Schwein/Calculator.h"
#include "../tag1_02Schwein/CalcClient.h"
class SoNicht: public testing::Test, public Calculator
{
protected:
	CalcClient object_under_test{*this};


public:
	double add(double a, double b) override{
		EXPECT_EQ(3.0, a);
		EXPECT_EQ(4.0, b);

		return 4711.0;
	}
};

