#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../source/blacklist_service.h"

class Mockblacklist_service : public blacklist_service{
public:
	MOCK_METHOD(bool, is_blacklisted, (const person& person), (const, override));

};
