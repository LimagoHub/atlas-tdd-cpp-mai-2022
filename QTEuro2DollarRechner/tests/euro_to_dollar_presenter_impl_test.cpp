//
// Created by JoachimWagner on 31.05.2022.
//
#include <stdexcept>
#include "euro_to_dollar_presenter_impl_test.h"

void euro_to_dollar_presenter_impl_test::SetUp() {

    object_under_test.set_view(& euro_to_dollar_viewMock);
    object_under_test.set_model(&euro_to_dollar_calculatorMock);
}

TEST_F(euro_to_dollar_presenter_impl_test, populate_items_happy_day_mask_is_filled_with_defaults) {
    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0"));
    EXPECT_CALL(euro_to_dollar_viewMock,  set_rechnen_enabled(true));

    object_under_test.populate_items();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen_nan_in_euro_field_error_in_dollar_field) {
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("Herbert"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl!"));

    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen_valid_euro_field_is_passed_to_service) {
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("10"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar(testing::_));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10)).WillOnce(testing::Return(0));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen_unexpected_exception_in_underlying_service_error_in_dollar_field) {
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("10"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Fehler im Service"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10)).WillOnce(testing::Throw(std::out_of_range{"Upps"}));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen_happy_day_result_in_dollar_field) {
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("10"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("10.000000"));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10)).WillOnce(testing::Return(10.0));
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state_nan_in_euro_field_rechnen_disabled) {
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("Peter"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(false));


    object_under_test.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state_valid_euro_field_rechnen_enabled) {
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(testing::Return("10"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));

    object_under_test.update_rechnen_action_state();
}