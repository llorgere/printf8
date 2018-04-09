#include "libftprintf.h"

static char	*ft_p_conv_null()
{
	char	*tab;
	
	if (!(tab = (char *)malloc(sizeof(*tab) * (6))))
		return (0);
	tab[0] = '(';
	tab[1] = 'n';
	tab[2] = 'i';
	tab[3] = 'l';
	tab[4] = ')';
	tab[5] = '\0';
	return (tab);
}

static char	*ft_llg_to_hex_malloc(long long unsigned int n, int j)
{
	char	*tab;

	if (!(tab = (char *)malloc(sizeof(*tab) * (j + 1))))
		return (0);
	tab[j] = '\0';
	if (n == 0)
		tab[0] = 48;
	while (n > 0)
	{
		if(n % 16 < 10)
			tab[j - 1] = (n % 16) + '0';
		else
			tab[j - 1] = (n % 16) + 'a' - 10;
		n = n / 16;
		j--;
	}
	return (tab);
}

char		*ft_p_conv(long long unsigned int n)
{
	long long unsigned int	i;
	int						j;
	char					*tmp;
	char					*tab;
	int						k;

	k = 2;
	i = n;
	j = 0;
	if (i == 0)
		return (ft_p_conv_null());
	while (i > 0)
	{
		i = i / 16;
		j++;
	}
	if (!(tab = malloc(sizeof(char) * (3 + j))))
		return (NULL);
	tab[0] = '0';
	tab[1] = 'x';
//	tab[2] = '\0';
	while (k <= (2 + j))
	{
		tab[k] = '\0';
		k++;
	}
	tmp = ft_llg_to_hex_malloc(n, j);
	tab = ft_strcat(tab, tmp);
	free(tmp);
	return (tab);
}
