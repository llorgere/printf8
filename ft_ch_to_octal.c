#include "libftprintf.h"
static char	*ft_ch_to_oct_malloc(unsigned char n, int j)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (j + 1))))
		return (0);
	tab[j] = '\0';
	if (n == 0)
		tab[0] = 48;
	while (n > 0)
	{
		tab[j - 1] = (n % 8) + '0';
		n = n / 8;
		j--;
	}
	return (tab);
}

char		*ft_ch_to_octal(unsigned char n)
{
	unsigned char	i;
	int				j;

	i = n;
	j = 0;
	while (i > 0)
	{
		i = i / 8;
		j++;
	}
	return (ft_ch_to_oct_malloc(n, j));
}
