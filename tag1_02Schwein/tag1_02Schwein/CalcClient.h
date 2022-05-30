#pragma once
#include <iostream>
#include "Calculator.h"
class CalcClient
{
	Calculator &calculator_; // Contract


public:
	CalcClient(Calculator& calculator)
		: calculator_(calculator)
	{
	}

	void run()
	{
		std::cout << calculator_.add(3, 4) << std::endl;
		std::cout << calculator_.add(3, 5) << std::endl;
		
	}
};

