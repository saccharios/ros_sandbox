#include <gtest/gtest.h>
#include "ros/ros.h"
#include "calculator.h"


TEST(Calculator, CalculatorLowValue)
{
    Calculator calculator;
    int init_value = 3;
    int value = calculator.do_some_math(init_value);
    EXPECT_EQ(value, init_value + 5);
}

TEST(Calculator, CalculatorHighValue)
{
    Calculator calculator;
    int init_value = 42;
    int value = calculator.do_some_math(init_value);
    EXPECT_EQ(value, 0);

}

