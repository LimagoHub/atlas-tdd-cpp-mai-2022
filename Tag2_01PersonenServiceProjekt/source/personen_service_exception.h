#pragma once
#include <string>
#include <exception>

class personen_service_execption :public std::exception
{
    std::string message;
public:
    personen_service_execption()
    {
    }

    personen_service_execption(std::string message)
            : message(message) {
    }



    personen_service_execption(exception const& _Other)
            : exception(_Other)
    {
    }

    const char *what() const noexcept override {
        return message.c_str();
    }
};