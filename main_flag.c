
#include "libftprintf.h"
#include <stdio.h>

int		main()
{
	printf("%lx\n", 4294967296);
	ft_printf("%lx\n", 4294967296);
	printf("%llx\n", 4294967296);
	ft_printf("%llx\n", 4294967296);
	printf("%jx\n", 4294967296);
	ft_printf("%jx\n", 4294967296);
	printf("%jx\n", -4294967296);
	ft_printf("%jx\n", -4294967296);
	return (0);
}
