#include <gtest/gtest.h>
#include <algorithm>

#include "myUFls.h"

TEST(test_suite_1, firsttest){
    int input = 15;
    ASSERT_EQ(convTen2Two(input), "1111") << "it is incorrect";
}

TEST(test_suite_1, secondtest){
    int input = 1000;
    ASSERT_EQ(convTen2Two(input), "1111101000") << "it is incorrect";
}