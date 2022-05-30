#pragma once

#include "gtest/gtest.h"
#include "../Tag1_01StapelProjekt/Stapel.h"
#include "../Tag1_01StapelProjekt/StapelException.h"

class StapelTest:public testing::Test
{
protected:
	Stapel object_under_test; // jeder Test hat eine neue frische Instanz
};

