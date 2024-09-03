#include "ft_printf.h"
#include <gtest/gtest.h>

template<typename... Args>
void compare_printf(const char* fmt_string, Args... args) {
    testing::internal::CaptureStdout();
    printf(fmt_string, args...);
    std::string stdPrintfResult = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    ft_printf(fmt_string, args...);
    std::string ftPrintfResult = testing::internal::GetCapturedStdout();

    EXPECT_EQ(stdPrintfResult, ftPrintfResult);
}

TEST(ft_printf_test, without_arguments) {
    compare_printf("Hello", "");
    compare_printf("", "");
}

TEST(ft_printf_test, string_conversion) {
    compare_printf("Hello %s", "World");
}

TEST(ft_printf_test, character_conversion) {
    compare_printf("Hello %c", 'q');
}

TEST(ft_printf_test, integer_conversion) {
    compare_printf("Hello %d", 1234);
}
