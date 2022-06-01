#pragma once
#include <iostream>
#include <gtest/gtest.h>
#include "../source/personen_service_impl.h"
#include "Mockblacklist_service.h"
#include "Mockpersonen_repository.h"
class personen_service_impl_test: public testing::Test
{
protected:
    Mockblacklist_service blacklist_serviceMock;
	Mockpersonen_repository repoMock;
	personen_service_impl object_under_test{ blacklist_serviceMock, repoMock };

    void my_callback_method() {
        std::cout << "Callback invoked" << std::endl;
    }
};

