#pragma once
#include <gtest/gtest.h>
#include "../Tag1_04PersonenServiceProjekt/personen_service_impl.h"
#include "Mockpersonen_repository.h"
class personen_service_impl_test: public testing::Test
{
protected:
	Mockpersonen_repository repoMock;
	personen_service_impl object_under_test{ repoMock };
};

