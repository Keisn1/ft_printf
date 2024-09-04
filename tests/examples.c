#include "libftprintf.h"
#include "stdio.h"

int	main(void)
{
	printf("Precision examples:\n");
	printf("printf(\"%%.4d\\n\", 12): ");
	printf("%.4d\n", 12);
	ft_printf("%.4d\n", 12);
	return (0);
}
