#include "libftprintf.h"
#include "stdio.h"

int	main(void)
{
	printf("Precision examples:\n");

	/* Precision examples */
	printf("printf(\"%%.4d\\n\", 12): ");
	printf("%.4d\n", 12);
	ft_printf("ft_printf(\"%%.4d\\n\", 12): ");
	ft_printf("%.4d\n", 12);

	return (0);
}
