#pragma once
#include <string>

#include "../source/Writer.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"

class Mockwriter : public Writer
{
public:
	MOCK_METHOD(void, write, (std::string), (override));
};