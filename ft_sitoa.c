#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stddef.h>
#include <wchar.h>
#include <sys/types.h>
#include "libftprintf.h"

static char	*ft_sitoa_min(short int n)
{
	int			j;
	char	*tab;

	j = 0;
	if (!(tab = (char *)malloc(sizeof(*tab) * (7))))
		return (0);
	tab[0] = '-';
	tab[6] = '\0';
	tab[5] = '8';
	n = -(n / 10);
	j = 5;
	while (n > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (tab);
}

static char	*ft_sitoa_malloc(short int n, int j)
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

char		*ft_sitoa(short int n)
{
	short int	i;
	int			j;

	i = n;
	j = 0;
	if (n == -32768)
		return (ft_sitoa_min(n));
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
	return (ft_sitoa_malloc(n, j));
}
