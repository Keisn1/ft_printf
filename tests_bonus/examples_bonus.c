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
	ft_printf("%3.1s", NULL);
	return (0);

}
