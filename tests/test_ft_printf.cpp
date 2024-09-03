#include "libftprintf.h"
#include "limits.h"
#include <gtest/gtest.h>
#include <unistd.h>

void compare_printf_wo_args(const char* fmt_string);
template<typename... Args>
void compare_printf(const char* fmt_string, Args... args);

TEST(ft_printf_test, without_arguments) {
    compare_printf_wo_args("Hello");
    compare_printf_wo_args("");
    compare_printf_wo_args("Hello %%");
}

TEST(ft_printf_test, string_conversion) {
    compare_printf("Hello %s", "World");
}

TEST(ft_printf_test, character_conversion) {
    compare_printf("Hello %c", 'q');
}

TEST(ft_printf_test, integer_conversion) {
    compare_printf("Hello %d", 1234);
    compare_printf("Hello %d", 976);
    compare_printf("Hello %d", -976);
    compare_printf("Hello %d", 0);
    compare_printf("Hello %d", -8);

    // with i instead of d
    compare_printf("Hello %i", -8);

    // with unsigned decimal (u)
    uint d = (uint)INT_MAX  + 10;
    compare_printf("Hello %u", d);


}

TEST(ft_printf_test, pointer_conversion) {
    int d = 1234;
    compare_printf("Hello %p", &d);
    compare_printf("Hello %p", 0);
    compare_printf("Hello %p", 1);
    compare_printf("Hello %p", -1);
}

TEST(ft_printf_test, conversion_combos) {
    int d = 1234;
    compare_printf("eins %s zwei %c drei %d vier %p", "world", 'q', d, &d);
}

void compare_printf_wo_args(const char* fmt_string) {
    testing::internal::CaptureStdout();
    int want_ret = printf("%s", fmt_string);
    std::string stdPrintfResult = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    int got_return = ft_printf(fmt_string);
    std::string ftPrintfResult = testing::internal::GetCapturedStdout();

    EXPECT_EQ(stdPrintfResult, ftPrintfResult);
    EXPECT_EQ(want_ret, got_return);
}

template<typename... Args>
void compare_printf(const char* fmt_string, Args... args) {
    testing::internal::CaptureStdout();
    int want_ret = printf(fmt_string, args...);
    std::string stdPrintfResult = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    int got_return = ft_printf(fmt_string, args...);
    std::string ftPrintfResult = testing::internal::GetCapturedStdout();

    EXPECT_EQ(stdPrintfResult, ftPrintfResult);
    EXPECT_EQ(want_ret, got_return);
}
