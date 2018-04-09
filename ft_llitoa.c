#include "libftprintf.h"

static char	*ft_llitoa_min(long long int n)
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

static char	*ft_llitoa_malloc(long long int n, int j)
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

char		*ft_llitoa(long long int n)
{
	long long	i;
	int			j;

	i = n;
	j = 0;
	if (i == -LLONG_MAX -1)
		return (ft_llitoa_min(n));
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
	return (ft_llitoa_malloc(n, j));
}
