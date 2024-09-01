#include <stdio.h>
#include <gtest/gtest.h>
#include "ft_printf.h"

TEST(ft_printf_suite, simple_test) {
    ::testing::internal::CaptureStdout();

    std::string want = ::testing::internal::GetCapturedStdout();
    printf("hello");


    ::testing::internal::CaptureStdout();
    std::string got = ::testing::internal::GetCapturedStdout();
    ft_printf("hello");

    // these are not c-strings, therefore can't use STREQ
    EXPECT_EQ(want, got);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
