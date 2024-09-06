#include "ft_printf.h"
#include "limits.h"
#include <gtest/gtest.h>
#include <unistd.h>

void compare_printf_wo_args(const char* fmt_string);
template<typename... Args>
void compare_printf(const char* fmt_string, Args... args);

TEST(ft_printf_test, PercentageFlag) {
    compare_printf_wo_args("Hello");
    compare_printf_wo_args("");
    compare_printf_wo_args("Hello %%");
    compare_printf_wo_args("%");
    compare_printf_wo_args(" %% ");
    compare_printf_wo_args(" %%%%");
    compare_printf_wo_args(" %% %% %% ");
    compare_printf_wo_args(" %%  %%  %% ");
    // TODO: This is not implemented yet
    // compare_printf_wo_args(" %%  %%  %% %");
}

TEST(ft_printf_test, string_conversion) {
    compare_printf("Hello %s", "World");
    compare_printf("Hello %s", "");

    // string
    compare_printf("Hello %10s", "hello");
    compare_printf("Hello %*s", -10, "hello");
    compare_printf("Hello %*.5s", -10, "hello");

    // NULL
    compare_printf("Hello %s", NULL);
}

TEST(ft_printf_test, character_conversion) {
    compare_printf("Hello %c", 'q');
    compare_printf(" %c %c %c ", '0', 11, '1');
    compare_printf(" %c %c %c ", '0', 1, '1');
    compare_printf(" %c %c %c ", '0', 2, '1');
    compare_printf(" %c %c %c ", '0', 3, '1');
    compare_printf(" %c %c %c ", '0', 4, '1');
    compare_printf(" %c %c %c ", '0', 5, '1');
    compare_printf(" %c %c %c ", '0', 6, '1');
    compare_printf(" %c %c %c ", '0', 127, '1');
    compare_printf(" %c %c %c ", '0', 0, '1');

    // char with precision and width
    compare_printf("Hello %10c",  'b');
    compare_printf("Hello %*c", -10, 'b');
    compare_printf("Hello %*.5c", -10,  'b');
}

TEST(ft_printf_test, IntegerConversions) {
    compare_printf("Hello %d", 1234);
    compare_printf("Hello %d", 976);
    compare_printf("Hello %d", -976);
    compare_printf("Hello %d", 0);
    compare_printf("Hello %d", -8);
    compare_printf("Hello %d", INT_MIN);
    compare_printf("Hello %d", INT_MAX);

    // integer with precision
    compare_printf("%.0d", 0);
    compare_printf("%.0d", 1);
    compare_printf("%.0d", 12);
    compare_printf("%.4d", 12);
    compare_printf("%.8d", 12);
    compare_printf("%.2d", 1234);
    compare_printf("%.10d", 2);
    compare_printf("Hello %.5d", -10, 0);
    compare_printf("Hello %.d", 0);
    compare_printf("%.12d", INT_MAX);
    compare_printf("%.4d", -12);
    compare_printf("%.*d", 8, 12);
    compare_printf("%.*d", -8, 12);

    // integer with field_width
    compare_printf("Hello %10d", 0);
    compare_printf("Hello %10d", 1234);
    compare_printf("Hello %10d", -12);
    compare_printf("Hello %*d", 20, -12);
    compare_printf("Hello %-10d", 0);
    compare_printf("Hello %d", -10, 0);

    // integer with field_width and precision
    compare_printf("Hello %100.12d", INT_MIN);
    compare_printf("Hello %*.*d", 10, 5, 1);

    // integer with field_width and precision and ZeroPadding
    compare_printf("Hello %010d", 1);
    compare_printf("Hello %010d", 0);
    compare_printf("Hello %0-10d", 1);
    compare_printf("Hello %0*d", -10, 1);
    compare_printf("Hello %0100.12d", INT_MIN);
    compare_printf("Hello %0*.*d", 10, 5, 1);
}

TEST(ft_printf_test, UnsignedIntegerConversions) {
    compare_printf(" %u ", 10);
    compare_printf(" %u ", 100);
    compare_printf(" %u ", 101);

    unsigned int d = (unsigned int)INT_MAX  + 10;
    compare_printf("Hello %u", d);
    compare_printf("Hello %u", -10);
    compare_printf("Hello %u", 0);
    compare_printf("Hello %u", ((unsigned int)INT_MAX)+((unsigned int)INT_MAX));

    // unsigned integer with precision
    compare_printf("%.*u", 8, 12);
    compare_printf("%.*u", -8, 12);
    compare_printf("%.0u", 12);
    compare_printf("%.0u", 0);

    // unsigned integer with width
    compare_printf("Hello %10u", 0);
    compare_printf("Hello %*u", -10, 0);
    compare_printf("Hello %*u", -10, ((unsigned int)INT_MAX)+10);

    // zero padding, width and precision
    compare_printf("Hello %0*.*u", 10, 5, 1);
    compare_printf("Hello %*.5u", -10, 0);
    compare_printf("Hello %*.5u", -10, ((unsigned int)INT_MAX)+10);
}

TEST(ft_printf_test, ZeroPadding) {
    compare_printf("Hello %0*.*x", 10, 5, 1);
    compare_printf("Hello %0*.*X", 10, 5, 1);
}

TEST(ft_printf_test, HexadecimalUnsignedIntegerConversions) {
    // hex
    compare_printf("Hello %x", 1234);
    compare_printf("Hello %x", 0);
    compare_printf("Hello %x", 16748);
    compare_printf("Hello %x", UINT_MAX);
    compare_printf("Hello %X", UINT_MAX);

    // hex with precision
    compare_printf("%.0x", 0);
    compare_printf("%.4x", 0);
    compare_printf("%.*x", 10, INT_MIN);
    compare_printf("%.*x", 20, INT_MIN);

    // hex with width and precision
    compare_printf("Hello %10x", 0);
    compare_printf("Hello %*.5x", -10, 0);
    compare_printf("Hello %*.5x", -10, ((unsigned int)INT_MAX)+10);
    compare_printf("Hello %*x", -10, 0);
    compare_printf("Hello %*x", -10, ((unsigned int)INT_MAX)+10);
}

TEST(ft_printf_test, pointer_conversion) {
    int d = 1234;
    compare_printf("Hello %p", &d);
    compare_printf("Hello %p", 0);
    compare_printf("Hello %p", 1);
    compare_printf("Hello %p", -1);

    // pointer with precision and width
    compare_printf("Hello %20p",  &d);
    compare_printf("Hello %*.5p", -20,  0);
    compare_printf("Hello %*.5p", -20,  1);
    compare_printf("Hello %*.5p", -20,  -1);

    // pointer with zero padding is undefined
}

TEST(ft_printf_test, conversion_combos) {
    int d = 1234;
    compare_printf("eins %s zwei %c drei %d vier %p", "world", 'q', d, &d);
}

void compare_printf_wo_args(const char* fmt_string) {
    testing::internal::CaptureStdout();
    int want_return = printf(fmt_string);
    std::string stdPrintfResult = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    int got_return = ft_printf(fmt_string);
    std::string ftPrintfResult = testing::internal::GetCapturedStdout();

    EXPECT_EQ(stdPrintfResult, ftPrintfResult);
    EXPECT_EQ(want_return, got_return);
}

template<typename... Args>
void compare_printf(const char* fmt_string, Args... args) {
    testing::internal::CaptureStdout();
    int want_return = printf(fmt_string, args...);
    std::string stdPrintfResult = testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    int got_return = ft_printf(fmt_string, args...);
    std::string ftPrintfResult = testing::internal::GetCapturedStdout();

    EXPECT_EQ(stdPrintfResult, ftPrintfResult);
    EXPECT_EQ(want_return, got_return);
}
