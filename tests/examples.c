#include "libftprintf.h"
#include "stdio.h"

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
	return (0);
}
