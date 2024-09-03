#include "libftprintf.h"
#include "stdio.h"

int	main(void)
{
	printf("printf output: \n");
	printf("%X", 123);
	printf("\n\n");
	printf("ft_printf output: \n");
	ft_printf("%X", 123);
	printf("\n");
	return (0);
}
