#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../tag1_02Schwein/Calculator.h"

class MockCalculator : public Calculator {
public:
	MOCK_METHOD(double, add, (double a, double b), (override));
};