#include "libftprintf.h"

static char	*ft_uctoa_malloc(unsigned char n, int j)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (j + 1))))
		return (0);
	tab[j] = '\0';
	if (n == 0)
		tab[0] = 48;
	while (n > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (tab);
}

char		*ft_uctoa(unsigned char n)
{
	unsigned char	i;
	int				j;

	i = n;
	j = 0;
	if (i == 0)
		j++;
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	return (ft_uctoa_malloc(n, j));
}
