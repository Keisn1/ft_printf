#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	/* Precision examples */
	printf("PRECISION EXAMPLES:\n");
	printf("------------------------------\n");
	printf("printf(\"%%.4d\\n\", 12): ");
	printf("%.4d\n", 12);
	ft_printf("ft_printf(\"%%.4d\\n\", 12): ");
	ft_printf("%.4d\n", 12);
	printf("------------------------------\n");
	printf("printf(\"%%.*d\\n\", 8, 12): ");
	printf("%.*d", 8, 12);
	printf("\n");
	fflush(stdout);
	ft_printf("ft_printf(\"%%.*d\\n\", 8, 12): ");
	ft_printf("%.*d", 8, 12);
	ft_printf("\n");
	printf("------------------------------\n");
	printf("printf(\"%%.*d\\n\", -8, 12): ");
	printf("%.*d", -8, 12);
	printf("\n");
	fflush(stdout);
	ft_printf("ft_printf(\"%%.*d\\n\", -8, 12): ");
	ft_printf("%.*d", -8, 12);
	ft_printf("\n");
	printf("------------------------------\n");
	printf("printf(\"%%.8x\\n\", 12): ");
	printf("%.8x", 12);
	printf("\n");
	fflush(stdout);
	ft_printf("ft_printf(\"%%.*8x\\n\", 12): ");
	ft_printf("%.8x", 12);
	ft_printf("\n");
	printf("------------------------------\n");

	/* left justification examples */
	printf("Minimum width exmaples\n");
	printf("------------------------------\n");
	printf("printf(\"%%10d\", 0): ");
	printf("%10d", 0);
	printf("\n");
	printf("ft_printf(\"%%10d\", 0): ");
	fflush(stdout);
	ft_printf("%10d", 0);
	ft_printf("\n");
	/* /\* left justification examples *\/ */
	/* printf("Left justification (flag -):\n"); */
	/* printf("------------------------------\n"); */
	/* printf("\"%%-.12d\": "); */
	/* printf("%-.12d", 1234); */
	/* printf("\n"); */
	/* fflush(stdout); */
	/* ft_printf("\"%%-.12d\": "); */
	/* ft_printf("%-.12d", 1234); */
	/* ft_printf("\n"); */
	/* printf("------------------------------\n"); */
	return (0);
}
