#include "libftprintf.h"

static char	*ft_imtoa_min(intmax_t n)
{
	int		j;
	char	*tab;

	j = 0;
	if (!(tab = (char *)malloc(sizeof(*tab) * (21))))
		return (0);
	tab[0] = '-';
	tab[20] = '\0';
	tab[19] = '8';
	n = -(n / 10);
	j = 19;
	while (n > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (tab);
}

static char	*ft_imtoa_malloc(intmax_t n, int j)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (j + 1))))
		return (0);
	tab[j] = '\0';
	if (n == 0)
		tab[0] = 48;
	if (n < 0)
	{
		tab[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (tab);
}

char		*ft_imtoa(intmax_t n)
{
	intmax_t	i;
	int			j;

	i = n;
	j = 0;
	if (n == LONG_MIN)
		return (ft_imtoa_min(n));
	else if (i <= 0)
	{
		i = -i;
		j++;
	}
	while (i > 0)
	{
		i = i / 10;
		j++;
	}
	return (ft_imtoa_malloc(n, j));
}
