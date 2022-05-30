#pragma once

#include <exception>

class personen_service_execption :public std::exception
{
public:
	personen_service_execption()
	{
	}

	personen_service_execption(char const* _Message)
		: exception(_Message)
	{
	}

	personen_service_execption(char const* _Message, int i)
		: exception(_Message, i)
	{
	}

	personen_service_execption(exception const& _Other)
		: exception(_Other)
	{
	}
};
