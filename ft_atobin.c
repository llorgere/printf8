#include "libftprintf.h"

int		ft_atobin(const char *str, size_t i)
{
	int		nb;

	nb = 0;
	while (*str <= '1' && *str >= '0' && i > 0)
	{
		nb = nb * 2;
		nb = nb + *str - '0';
		str++;
		i--;
	}
	return (nb);
}
