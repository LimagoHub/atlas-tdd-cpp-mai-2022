#pragma once
#include "Calculator.h"
class CalculatorImpl : public Calculator
{

public:
	double add(double a, double b) override
	{
		return a + b;
	}
};

