#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
/*
char	**ft_watinit(const char *arg0, int sizetab);
int		ft_size_tab(const char *str);
*/
//char	*ft_strndup(const char *s, size_t n);
wii		ft_watinit(const char *arg0, int sizetab)
{
	int			i;
	int			j;
	int			k;
	const char 	*tmp;
/*	int			nb_conv;
	int			*pos_conv;
	char		**tab;
*/	wii			wiit;

	i = 0;
	j = 0;
	k = 0;
	wiit.nb_conv = 0;
//	printf("arg0 est [%s] et sizetab est %d\n", arg0, sizetab);
	wiit.pos_conv = malloc(sizeof(int) * (sizetab + 1));
	wiit.pos_conv[sizetab] = -1;
	wiit.tab = malloc(sizeof(char *) * (sizetab + 1));
	wiit.tab[sizetab] = NULL;
	tmp = arg0;
/*	wiit.tab[sizetab] = malloc(sizeof(char) * 1);
	wiit.tab[sizetab][0] = '\0';
*/	while (tmp[i] != '\0')
	{
		k = i;
		while (tmp[i] != '%' && tmp[i] != '\0')
		{
			i++;
			if (tmp[i] == '\0' || tmp[i] == '%')
			{
				wiit.tab[j] = ft_strndup(tmp + k, (i - k));
				wiit.pos_conv[j] = 0;
				j++;
			}
		}
		if (tmp[i] == '\0')
			return (wiit);
		else if (tmp[i] == '%')
		{
			k = i;
			i++;
			while (tmp[i] != 'd' && tmp[i] != 'i' && tmp[i] != 's' && tmp[i] != 'p' && tmp[i] != 'S' && tmp[i] !='D' && tmp[i] !='U' && tmp[i] !='O' && tmp[i] != 'o' && tmp[i] !='u' && tmp[i] !='x' && tmp[i] !='X' && tmp[i] !='c' && tmp[i] !='C'  && tmp[i] != '\0' && tmp[i] != '%')
			{
				if (tmp[i] == '+' || tmp[i] == ' ' || tmp[i] == '#' || tmp[i] == '-' || tmp[i] == '.' || (tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == 'h' || tmp[i] == 'j' || tmp[i] == 'z' || tmp[i] == 'l')
					i++;
				else
				{
					while (tmp[i] != '%' && tmp[i] != '\0')
						i++;
					if (tmp[i] == '%')
						i--;
					break;
	//				printf("i est %d et k est %d et tmp[i] est %c\n", i, k, tmp[i]);
				}
			}
//			printf("tmp[i] est [%c]", tmp[i]);
			wiit.tab[j] = ft_strndup(tmp + k, (i - k + 1));
			wiit.nb_conv++;
			wiit.pos_conv[j] = 1;
			j++;
// cas d'erreur ou % pas suivi de conversion
			if (tmp[i] == '\0')
				return (wiit);
			i++;
		}
		else
			i++;
	}
	return (wiit);
}

/*
		else if (tmp[i] == '%' && tmp[i + 1] == '%')
		{
			wiit.tab[j] = malloc(sizeof(char) * 2);
			wiit.tab[j][0] = '%';
			wiit.tab[j][1] = '\0';
			i = i + 2;
			wiit.pos_conv[j] = 0;
			j++;
		}
*/
