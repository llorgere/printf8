/*#include <stdlib.h>
#include <stdarg.h>
#include <inttypes.h>
#include <stddef.h>
#include <wchar.h>
#include <sys/types.h>
*/
#include "libftprintf.h"

static char	*ft_ctoa_min()
{
//	int			j;
	char	*tab;

//	j = 0;
	if (!(tab = (char *)malloc(sizeof(*tab) * (5))))
		return (0);
	tab[0] = '-';
	tab[1] = '1';
	tab[2] = '2';
	tab[3] = '8';
	tab[4] = '\0';
/*	n = -(n / 10);
	j = 10;
	while (n > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
*/	return (tab);
}

static char	*ft_ctoa_malloc(char n, int j)
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

char		*ft_ctoa(char n)
{
	char	i;
	int		j;

//	printf("\nn est [%hhd]\n", n);
	i = n;
	j = 0;
	if (n == -128)
		return (ft_ctoa_min());
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
	return (ft_ctoa_malloc(n, j));
}
