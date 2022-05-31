#pragma once
#include <iostream>
#include "writer.h"
class consolen_writer :
    public Writer
{
public:
	void write(std::string message) override
	{
		std::cout << message << std::endl;
	}
};

