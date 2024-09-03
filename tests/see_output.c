#include "libftprintf.h"
#include "stdio.h"

int	main(void)
{
	printf("printf output: \n");
	printf("hello");
	printf("\n\n");
	printf("ft_printf output: \n");
	ft_printf("hello");
	printf("\n");
	return (0);
}
