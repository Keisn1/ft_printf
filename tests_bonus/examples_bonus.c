#include "ft_printf_bonus.h"
#include <stdio.h>

int	main(void)
{
	/* /\* Precision examples *\/ */
	/* printf("PRECISION EXAMPLES:\n"); */
	/* printf("------------------------------\n"); */
	/* printf("(\"%%.4d\\n\", 12): "); */
	/* printf("%.4d\n", 12); */
	/* printf("(\"%%.4d\\n\", 12): "); */
	/* fflush(stdout); */
	/* ft_printf("%.4d\n", 12); */
	/* printf("------------------------------\n"); */
	/* printf("(\"%%.*d\\n\", 8, 12): "); */
	/* printf("%.*d", 8, 12); */
	/* printf("\n"); */
	/* printf("(\"%%.*d\\n\", 8, 12): "); */
	/* fflush(stdout); */
	/* ft_printf("%.*d", 8, 12); */
	/* ft_printf("\n"); */
	/* printf("------------------------------\n"); */
	/* printf("(\"%%.*d\\n\", -8, 12): "); */
	/* printf("%.*d", -8, 12); */
	/* printf("\n"); */
	/* printf("(\"%%.*d\\n\", -8, 12): "); */
	/* fflush(stdout); */
	/* ft_printf("%.*d", -8, 12); */
	/* ft_printf("\n"); */
	/* printf("------------------------------\n"); */
	/* printf("(\"%%.8x\\n\", 12): "); */
	/* printf("%.8x", 12); */
	/* printf("\n"); */
	/* printf("(\"%%.8x\\n\", 12): "); */
	/* fflush(stdout); */
	/* ft_printf("%.8x", 12); */
	/* printf("\n"); */
	/* printf("------------------------------\n"); */

	/* /\* left justification examples *\/ */
	/* printf("Minimum width exmaples\n"); */
	/* printf("------------------------------\n"); */
	/* printf("(\"%%10d\", 0): "); */
	/* printf("%10d", 0); */
	/* printf("\n"); */
	/* printf("(\"%%10d\", 0): "); */
	/* fflush(stdout); */
	/* ft_printf("%10d", 0); */
	/* ft_printf("\n"); */
	/* printf("------------------------------\n"); */
	/* printf("(\"%%10d\", -12): "); */
	/* printf("Hello %10d", -12); */
	/* printf("\n"); */
	/* printf("(\"%%10d\", -12): "); */
	/* fflush(stdout); */
	/* ft_printf("Hello %10d", -12); */
	/* ft_printf("\n"); */
	/* printf("------------------------------\n"); */
	/* printf("(Hello \"%%*d\", 20, -12): "); */
	/* printf("Hello %*d", 20, -12); */
	/* printf("\n"); */
	/* printf("(Hello \"%%*d\", 20, -12): "); */
	/* fflush(stdout); */
	/* ft_printf("Hello %*d", 20, -12); */
	/* ft_printf("\n"); */
	/* printf("------------------------------\n"); */
	/* printf("(\"%%-10d\", 0): "); */
	/* printf("%-10d", 0); */
	/* printf("\n"); */
	/* printf("(\"%%-10d\", 0): "); */
	/* fflush(stdout); */
	/* ft_printf("%-10d", 0); */
	/* ft_printf("\n"); */
	/* printf("------------------------------\n"); */
	/* printf("(\"Hello %%*u\", -10, 0): "); */
	/* printf("Hello %*u", -10, 0); */
	/* printf("\n"); */
	/* printf("(\"Hello %%*u\", -10, 0): "); */
	/* fflush(stdout); */
	/* ft_printf("Hello %*u", -10, 0); */
	/* ft_printf("\n"); */

	/* /\* zero padding examples *\/ */
	/* printf("zero padding examples\n"); */
	/* printf("------------------------------\n"); */
	/* printf("\"Hello %%0*.*d\", 10, 5, 1\""); */
	/* printf("Hello %0*.*d", 10, 5, 1); */
	/* printf("\n"); */
	/* printf("\"Hello %%0*.*d\", 10, 5, 1\""); */
	/* fflush(stdout); */
	/* ft_printf("Hello %0*.*d", 10, 5, 1); */
	/* ft_printf("\n"); */

	/* printf("------------------------------\n"); */
    /* printf("(\" %%04d \", -14): "); */
    /* printf(" %04d ", -14); */
    /* printf("\n"); */
    /* printf("(\" %%04d \", -14): "); */
	/* fflush(stdout); */
    /* ft_printf(" %04d ", -14); */
	/* ft_printf("\n"); */

	/* /\* %% bonus *\/ */
	/* printf("\n\n"); */
	/* printf("BONUS"); */
	/* printf("------------------------------\n"); */
	/* printf("# - Hash Flag\n"); */
	/* printf("------------------------------\n"); */
	/* printf("%#x", 54); */
	/* ft_printf("Hello %*.5p", -20,  0); */
	/* ft_printf(" %c %c %c ", '0', 0, '1'); */
	/* ft_printf("Hello %10s", "hello"); */
	/* ft_printf("Hello %s", NULL); */
	/* ft_printf("%3.1s", NULL); */
	/* printf("% d",42); */
	/* printf("%0#30x", 42); */
	/* int d = 1234; */
	/* printf("Hello %.5p",  &d); */
	/* printf("Hello %*.5p", -20,  1); */

    // Using %c specifier without hh flag
	printf("BONUS: hh flag");
	printf("------------------------------\n");
    signed char sc = 'A'; // ASCII value 65
    signed char sc_neg = -65;

    // Example with unsigned char
    unsigned char uc = 200;

    // Signed char with `d` specifier
    printf("Signed char (d): %hhd\n", sc);       // Output: 65
    printf("Signed char (d neg): %hhd\n", sc_neg); // Output: -65

    // Signed char with `i` specifier
    printf("Signed char (i): %hhi\n", sc);       // Output: 65
    printf("Signed char (i neg): %hhi\n", sc_neg); // Output: -65

    // Unsigned char with `u` specifier
    printf("Unsigned char (u): %hhu\n", uc);     // Output: 200

    // Unsigned char with `o` specifier (octal)
    printf("Unsigned char (o): %hho\n", uc);     // Output: 310

    // Unsigned char with `x` specifier (hexadecimal)
    printf("Unsigned char (x): %hhx\n", uc);     // Output: c8

    // Unsigned char with `X` specifier (hexadecimal uppercase)
    printf("Unsigned char (X): %hhX\n", uc);     // Output: C8

    // Edge case with maximum value of signed char
    sc = 127; // Max value for signed char
    printf("Max signed char (d): %hhd\n", sc);   // Output: 127

    // Edge case with minimum value of signed char
    sc = -128; // Min value for signed char
    printf("Min signed char (d): %hhd\n", sc);   // Output: -128

    // Edge case with maximum value of unsigned char
    uc = 255; // Max value for unsigned char
    printf("Max unsigned char (u): %hhu\n", uc); // Output: 255
	return (0);

}
