#include "ft_printf_bonus.h"
#include <limits.h>
#include <gtest/gtest.h>
#include <unistd.h>

void compare_printf_wo_args(const char* fmt_string);
template<typename... Args>
void compare_printf(const char* fmt_string, Args... args);

TEST(ft_printf_test, nFlag) {
    int count_printf;
    int count_ft_printf;
    printf("Hello World%n\n", &count_printf);
    ft_printf("Hello World%n\n", &count_printf);
    EXPECT_EQ(count_printf, count_ft_printf);
}

TEST(ft_printf_test, HHFlag) {
    signed char sc = 'A'; // ASCII value 65
    signed char sc_neg = -65;
    unsigned char uc = 200;
    compare_printf("Signed char (d): %hhd\n", sc);       // Output: 65
    compare_printf("Signed char (d neg): %hhd\n", sc_neg); // Output: -65
    compare_printf("Unsigned char (u): %hhu\n", uc);     // Output: 200

    // Unsigned char with `x` specifier (hexadecimal)
    compare_printf("Unsigned char (x): %hhx\n", uc);     // Output: c8

    // Unsigned char with `X` specifier (hexadecimal uppercase)
    compare_printf("Unsigned char (X): %hhX\n", uc);     // Output: C8

    // Edge case with maximum value of signed char
    sc = 127; // Max value for signed char
    compare_printf("Max signed char (d): %hhd\n", sc);   // Output: 127

    // Edge case with minimum value of signed char
    sc = -128; // Min value for signed char
    compare_printf("Min signed char (d): %hhd\n", sc);   // Output: -128

    // Edge case with maximum value of unsigned char
    uc = 255; // Max value for unsigned char
    compare_printf("Max unsigned char (u): %hhu\n", uc); // Output: 255

    unsigned char pos_char = 100;
    compare_printf("Expect 100: %hhu\n", pos_char);

    signed char neg_char = -20;
    compare_printf("Expect -20: %hhd\n", neg_char);

    unsigned char overflow = 260;
    compare_printf("Expect 4: %hhu\n", overflow);

    signed char overflow_signed = 130;
    compare_printf("Expect -126: %hhd\n", overflow_signed);
}

TEST(ft_printf_test, ft_printf_test) {
    // integer conversion
    compare_printf("%5.i", 0);
    compare_printf("%-5.0i", 0);
    compare_printf("%-5.i", 0);
    compare_printf("%5.0d", 0);
    compare_printf("%5.d", 0);
    compare_printf("%-5.0d", 0);
    compare_printf("%-5.d", 0);

    // unsigned conversion
    compare_printf("%5.0u", 0);
    compare_printf("%5.u", 0);
    compare_printf("%-5.0u", 0);
    compare_printf("%-5.u", 0);

    // unsigned hex
    compare_printf("%5.0x", 0);
    compare_printf("%5.x", 0);
    compare_printf("%-5.0x", 0);
    compare_printf("%-5.x", 0);
    compare_printf("%5.0x", 0);
    compare_printf("%5.x", 0);
    compare_printf("%-5.0x", 0);
    compare_printf("%-5.x", 0);

    compare_printf("%--120.50d%-%%-112.167X%-32.65u" ,-1355834522,3814946551u,404243169u);
}

TEST(ft_printf_test, PlusFlag) {
    compare_printf("%+d", 42);
}

TEST(ft_printf_test, Blank) {
    compare_printf("% d", 42);
}

TEST(ft_printf_test, FlagCombinations) {
    compare_printf("%0#30x", 42);
    compare_printf("%#030x", 42);
}

TEST(ft_printf_test, WeirtInput) {
    compare_printf_wo_args("%5%");
    compare_printf_wo_args("%-5%");
    compare_printf_wo_args("%-05%");
    compare_printf_wo_args("percent 2 %12%");
    compare_printf_wo_args("percent 3 %-12%");
}

TEST(ft_printf_test, HashFlags) {
    compare_printf("%#x", 54);
    compare_printf("%#X", 54);
    compare_printf("%#X", 54);
    compare_printf("Hello %p", ULONG_MAX);
    compare_printf(" %#x ", 0);

    compare_printf(" %#x ", LONG_MIN);
    compare_printf(" %#x %#x %#x %#x %#x %#x %#x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    compare_printf(" %#X ", 0);
    compare_printf(" %#X ", LONG_MIN);
    compare_printf(" %#X %#X %#X %#X %#X %#X %#X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}

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

    // with precision
    compare_printf("%.3s", "hello");
    compare_printf("%.s", "hello");
    compare_printf("%.0s", "hello");
    compare_printf("%.3s%.2s", "holla", "welt");
    compare_printf("%.2s%.7s", "hello", "world");
    compare_printf("%.7s%.2s", "hello", "world");
    compare_printf("%7.5s", "bombastic");;
    compare_printf("%-7.5s", "tubular");
    compare_printf("%.s", NULL);
    compare_printf("%.06s", NULL);
    compare_printf("%.05s", NULL);
    compare_printf("%.03s", NULL);
    compare_printf("%3.1s", NULL);
    compare_printf("%9.1s", NULL);
    compare_printf("%-3.1s", NULL);
    compare_printf("%-9.1s", NULL);

    compare_printf("p3 %.4s\n", NULL);
    compare_printf("%50.2s", NULL);


    compare_printf("%1.20s", NULL);
    compare_printf("%1.4s", "string longer that 5");
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

    // 0 and negative values
    compare_printf(" %04d ", -14);
    compare_printf(" %05d ", -15);
    compare_printf(" %06d ", -16);

    compare_printf(" %011d ", LONG_MAX);
    compare_printf(" %013d ", UINT_MAX);
    compare_printf(" %014d ", ULONG_MAX);
    compare_printf(" %015d ", 9223372036854775807LL);

    compare_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    compare_printf(" %05i ", -15);
    compare_printf(" %06i ", -16);
    compare_printf(" %01i ", -99);
    compare_printf(" %012i ", LONG_MIN);
    compare_printf(" %014i ", ULONG_MAX);
    compare_printf(" %015i ", 9223372036854775807LL);
    compare_printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    compare_printf("%08.5i", 34);
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
    compare_printf(" %01u ", 0);
    // TODO: not sure if this is doing the right thing
    // compare_printf("%08.5u", 34);
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
    // precision is undefined behavior
    compare_printf("Hello %20p",  &d);
    compare_printf("Hello %*.5p", -20,  0);
    compare_printf("Hello %*.5p", -20,  1);
    // compare_printf("Hello %*.5p", -20,  -1);

    // pointer with zero padding is undefined
    // compare_printf("Hello %.5p",  &d);
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
