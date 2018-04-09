#include "libftprintf.h"
#include <stdio.h>
int		main()
{
	printf("nm[%d]", printf("%030S}", L"我是一只猫。"));
	printf("ft[%d]", ft_printf("%030S}", L"我是一只猫。"));
	return (0);
}
