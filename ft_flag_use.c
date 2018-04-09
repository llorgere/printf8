#include "libftprintf.h"
#include <stdio.h>

char	*ft_add_plus(char *str, int len)
{
	char	*tab;
	int i;

	i = 1;
	if(str[0] == '-')
		return (str);
	else
	{
		if (!(tab = malloc(sizeof(char) * 2 + len)))
			return (NULL);
		tab[0] = '+';
//		tab[len + 1] = '\0';
		while (i <= len + 1)
		{
			tab[i] = '\0';
			i++;
		}
		tab = ft_strcat(tab, str);
	//	printf("tab est [%s]", tab);
		free(str);
		return (tab);
	}
}

static char	*ft_add_plus0(char *str, flag_type flag, int len)
{
	if(flag.width > len && str[0] != '-')
	{
		str[0] = '+';
		return (str);
	}
	else 
		return (ft_add_plus(str, len));
}

static char	*ft_add_space0(char *str, flag_type flag, int len)
{
	if(flag.width > len && str[0] != '-')
	{
		str[0] = ' ';
		return (str);
	}
	else 
		return (ft_add_space(str, len));
}

char	*ft_add_space(char *str, int len)
{
	char	*tab;
	int		i;

	i = 1;
	if(str[0] == '-')
		return (str);
	else
	{
		if (!(tab = malloc(sizeof(char) * 2 + len)))
			return (NULL);
		tab[0] = ' ';
//		tab[len + 1] = '\0';
		while (i <= len + 1)
		{
			tab[i] = '\0';
			i++;
		}
		tab = ft_strcat(tab, str);
		free(str);
		return (tab);
	}
}

char	*ft_add_preci_empty()
{
	char	*tab;

	if(!(tab = malloc(sizeof(char) * 1)))
		return (NULL);
	tab[0] = '\0';
	return (tab);
}

char	*ft_add_dies_o(char *str, int len)
{
	char	*tab;
	int		i;

	i = 1;
//	printf("add dies o 1| str est [%s]\n", str);
	if (str[0] == '0')
		return (str);
	if (!(tab = malloc(sizeof(char) * 2 + len)))
		return (NULL);
//	printf("add dies o 2| str est [%s]\n", str);
	tab[0] = '0';
	while (i <= len + 1)
	{
		tab[i] = '\0';
		i++;
	}
	tab = ft_strcat(tab, str);
	free(str);
//	printf("add dies o 3| tab est [%s]\n", tab);
	return (tab);
}

char	*ft_add_dies_x(char *str, int len)
{
	char	*tab;
	int		i;

	i = 2;
	if (!(tab = malloc(sizeof(char) * 3 + len)))
		return (NULL);
	tab[0] = '0';
	tab[1] = 'x';
//	tab[len + 2] = '\0';
	while (i <= len + 2)
	{
		tab[i] = '\0';
		i++;
	}
	tab = ft_strcat(tab, str);
	free(str);
	return (tab);
}

char	*ft_add_dies_X(char *str, int len)
{
	char	*tab;
	int		i;

	i = 2;
	if (!(tab = malloc(sizeof(char) * 3 + len)))
		return (NULL);
	tab[0] = '0';
	tab[1] = 'X';
//	tab[len + 2] = '\0';
	while (i <= len + 2)
	{
		tab[i] = '\0';
		i++;
	}
	tab = ft_strcat(tab, str);
	free(str);
	return (tab);
}

static char	*ft_add_dies_o0(char *str, flag_type flag, int len)
{
	if(flag.width > len)
	{
		str[0] = '0';
		return (str);
	}
	else 
		return (ft_add_dies_o(str, len));
}

static char	*ft_add_dies_x0(char *str, flag_type flag, int len)
{
	char	*tab;
	int		i;

	i = 2;
	if(flag.width > len + 1)
	{
		str[0] = '0';
		str[1] = 'x';
		return (str);
	}
	else if (flag.width == len + 1)
	{
		if(!(tab = malloc(sizeof(char) * flag.width + 2)))
			return (0);
		tab[0] = '0';
		tab[1] = 'x';
		while (i <= flag.width + 1)
		{
			tab[i] = '\0';
			i++;
		}
		tab = ft_strcat(tab, str + 1);
		free(str);
		return (tab);
	}
	else 
		return (ft_add_dies_x(str, len));
}

static char	*ft_add_dies_X0(char *str, flag_type flag, int len)
{
	char	*tab;
	int		i;

	i = 2;
	if(flag.width > len + 1)
	{
		str[0] = '0';
		str[1] = 'X';
		return (str);
	}
	else if (flag.width == len + 1)
	{
		if(!(tab = malloc(sizeof(char) * flag.width + 2)))
			return (0);
		tab[0] = '0';
		tab[1] = 'X';
		while (i <= flag.width + 1)
		{
			tab[i] = '\0';
			i++;
		}
		tab = ft_strcat(tab, str + 1);
		free(str);
		return (tab);
	}
	else 
		return (ft_add_dies_X(str, len));
}

static char	*ft_add_dies0(char *str, flag_type flag, int len)
{
//	printf("tab est [%s] et len est [%d] && flag.presci est [%d] && flag.conv_num est [%d]\n", str, len, flag.preci, flag.conv_num);
	if (len == 0 && flag.preci == 0 && flag.conv_num != 3 &&
				flag.conv_num != 11 && flag.conv_num != 18 &&
				flag.conv_num != 23 && flag.conv_num != 28 &&
				flag.conv_num != 33 && flag.conv_num != 38)
	{
//		printf("test de add dies 1\n");
		return (str);
	}
	else if (flag.dies == 1 && ((str[0] != '0' && len == 1) ||
				(len > 1) || (len == 0)))
	{
		if (flag.conv_num == 3 || flag.conv_num == 11 ||
				flag.conv_num == 18 || flag.conv_num == 23 ||
				flag.conv_num == 28 || flag.conv_num == 33 ||
				flag.conv_num == 38)
			return (ft_add_dies_o0(str, flag, len));
		else if (flag.conv_num == 4 || flag.conv_num == 12 ||
				flag.conv_num == 19 || flag.conv_num == 24 ||
				flag.conv_num == 29 || flag.conv_num == 34 ||
				flag.conv_num == 39)
			return (ft_add_dies_x0(str, flag,  len));
		else
		{
//			printf("test de add dies 2\n");
			return (ft_add_dies_X0(str, flag, len));
		}
	}
/*	else if (flag.dies == 1 && len == 1 && str[0] == '0' &&
			flag.preci == 0 && (flag.conv_num != 3 || flag.conv_num != 11 ||
				flag.conv_num != 18 || flag.conv_num != 23 ||
				flag.conv_num != 28 || flag.conv_num != 33 ||
				flag.conv_num != 38))
		return (str);
*/	else
	{
//		printf("test de add dies 3\n");
		return (str);
	}
}

char	*ft_add_dies(char *str, flag_type flag, int len)
{
//	printf("tab est [%s] et len est [%d] && flag.presci est [%d] && flag.conv_num est [%d]\n", str, len, flag.preci, flag.conv_num);
	if (len == 0 && flag.preci == 0 && flag.conv_num != 3 &&
				flag.conv_num != 11 && flag.conv_num != 18 &&
				flag.conv_num != 23 && flag.conv_num != 28 &&
				flag.conv_num != 33 && flag.conv_num != 38)
	{
//		printf("test de add dies 1\n");
		return (str);
	}
	else if (flag.dies == 1 && ((str[0] != '0' && len == 1) ||
				(len > 1) || (len == 0)))
	{
		if (flag.conv_num == 3 || flag.conv_num == 11 ||
				flag.conv_num == 18 || flag.conv_num == 23 ||
				flag.conv_num == 28 || flag.conv_num == 33 ||
				flag.conv_num == 38)
			return (ft_add_dies_o(str, len));
		else if (flag.conv_num == 4 || flag.conv_num == 12 ||
				flag.conv_num == 19 || flag.conv_num == 24 ||
				flag.conv_num == 29 || flag.conv_num == 34 ||
				flag.conv_num == 39)
			return (ft_add_dies_x(str, len));
		else
		{
//			printf("test de add dies 2\n");
			return (ft_add_dies_X(str, len));
		}
	}
/*	else if (flag.dies == 1 && len == 1 && str[0] == '0' &&
			flag.preci == 0 && (flag.conv_num != 3 || flag.conv_num != 11 ||
				flag.conv_num != 18 || flag.conv_num != 23 ||
				flag.conv_num != 28 || flag.conv_num != 33 ||
				flag.conv_num != 38))
		return (str);
*/	else
	{
//		printf("test de add dies 3\n");
		return (str);
	}
}

char	*ft_addw(char *str, flag_type flag, int len)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = malloc(sizeof(char) * flag.width + 1)))
		return (NULL);
	tab[flag.width] = '\0';
	while (i < (flag.width - len))
	{
		tab[i] = ' ';
		i++;
	}
	while (i < flag.width)
	{
		tab[i] = '\0';
		i++;
	}
	tab = ft_strcat(tab, str);
	free(str);
	return (tab);
}

char	*ft_addw0(char *str, flag_type flag, int len)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = malloc(sizeof(char) * flag.width + 1)))
		return (NULL);
	tab[flag.width] = '\0';
	if (str[0] == '-' && (flag.conv_num == 1 || flag.conv_num == 9 ||
				flag.conv_num == 16 || flag.conv_num == 21 ||
				flag.conv_num == 26 || flag.conv_num == 31 ||
				flag.conv_num == 36))
	{
		tab[i] = '-';
		i++;
		str[0] = '0';
	}
	while (i < (flag.width - len))
	{
		tab[i] = '0';
		i++;
	}
	while (i < flag.width)
	{
		tab[i] = '\0';
		i++;
	}
	tab = ft_strcat(tab, str);
	free(str);
	return (tab);
}

char	*ft_addwmin(char *str, flag_type flag, int len)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = malloc(sizeof(char) * flag.width + 1)))
		return (NULL);
	tab[flag.width] = '\0';
	while (i < (len))
	{
		tab[i] = str[i];
		i++;
	}
	while (i < flag.width)
	{
		tab[i] = ' ';
		i++;
	}
	free(str);
	return (tab);
}

static char	*ft_addwf0(char *str, flag_type flag, int len)
{
	if (flag.dies == 1)
		return (ft_add_dies0(str, flag, len));
	if (flag.plus == 1)
		return (ft_add_plus0(str, flag, len));
	else if (flag.space == 1)
		return (ft_add_space0(str, flag, len));
	else
		return (str);
}

char	*ft_addwf(char *str, flag_type flag, int len)
{
	if (flag.dies == 1)
		return (ft_add_dies(str, flag, len));
	else if (flag.plus == 1)
		return (ft_add_plus(str, len));
	else if (flag.space == 1)
		return (ft_add_space(str, len));
	else
		return (str);
}

char	*ft_winopr(char *str, flag_type flag, int len)
{
	char	*tab;

	if (flag.width <= len)
		return (ft_nowinopr(str, flag, len));
	else
	{
		if (flag.minus == 1)
		{
			tab = ft_addwf(str, flag, len);
			return (ft_addwmin(tab, flag, ft_strlen(tab)));
		}
		else if (flag.zero == 1)
		{
			tab = ft_addw0(str, flag, len);
			return (ft_addwf0(tab, flag, len));
		}
		else
		{
			tab = ft_addwf(str, flag, len);
			return (ft_addw(tab, flag, ft_strlen(tab)));
		}
	}
}

char	*ft_nowipr(char *str, flag_type flag, int len)
{
	char	*tab;
	int		i;

//	printf("test de nowipr\n");
	i = 0;
	if (flag.conv_num == 7 || flag.conv_num == 15)
	{
		if (flag.preci >= len)
			return (ft_nowinopr(str, flag, len));
		else
		{
			tab = ft_strndup(str, flag.preci);
			free(str);
			return (ft_nowinopr(tab, flag, flag.preci));
		}
	}
	else if (len == 1 && str[0] == '0' && flag.preci == 0)
	{
		tab = ft_add_preci_empty();
		free(str);
		return (ft_nowinopr(tab, flag, 0));
	}
	else
	{	if (str[0] == '-')
		len--;
		if (flag.preci <= len)
			return (ft_nowinopr(str, flag, len));
		else
		{
			if (str[0] == '-')
			{
				if (!(tab = malloc(sizeof(char) * flag.preci + 2)))
					return (NULL);
				tab[i] = '-';
				tab[flag.preci + 1] = '\0';
				str[0] = '0';
				i++;
			}
			else
			{
				if (!(tab = malloc(sizeof(char) * flag.preci + 1)))
					return (NULL);
				tab[flag.preci] = '\0';
			}
			while (i < (flag.preci - len))
			{
				tab[i] = '0';
				i++;
			}
			while (i < flag.preci)
			{
				tab[i] = '\0';
				i++;
			}
			tab = ft_strcat(tab, str);
			free(str);
			return (ft_nowinopr(tab, flag, ft_strlen(tab)));
		return (tab);
		}
	}
}

char	*ft_nowinopr(char *str, flag_type flag, int len)
{
//	printf("test de nowinopr et str est[%s]\n", str);
	if (flag.dies == 1)
	{
		return (ft_add_dies(str, flag, len));
	}
	else if (flag.plus == 1)
	{
		return (ft_add_plus(str, len));
	}
	else if (flag.space == 1)
	{
		return (ft_add_space(str, len));
	}
	else
		return (str);
}

char	*ft_wipr(char *str, flag_type flag, int len)
{
	char	*tmp;

//	printf("test de wipr\n");
	if (flag.width <= len && flag.conv_num != 7 && flag.conv_num != 15)
		return (ft_nowipr(str, flag, len));
	else
	{
		tmp = ft_nowipr(str, flag, len);
		flag.space = 0;
		flag.plus = 0;
		flag.dies = 0;
//		printf("test de wipr 2 tmp est [%s]\n", tmp);
//		printf("test de wipr 3\n");
		return (ft_winopr(tmp, flag, ft_strlen(tmp)));
	}
}

char	*ft_flag_use(char *str, flag_type flag)
{
	int		len;

//	printf("test boucle 1\n");
	len = ft_strlen(str);
//	printf("test boucle 2\n");
	flag = ft_flag_adjust(flag);
//	printf("test des valeurs des flags\ncn : [%d] | wi : [%d] | pr : [%d] | - : [%d] | + : [%d] | # : [%d] | 0 : [%d] | sp : [%d] | . : [%d] | et str est [%s]\n", flag.conv_num, flag.width, flag.preci, flag.minus, flag.plus, flag.dies, flag.zero, flag.space, flag.point, str);
/*	if (flag.conv_num == 6 || flag.conv_num == 14)
		return (ft_special_c(str, flag));
*///	if ((flag.W > -1 && flag.preci < 0) || (flag.W > -1 && flag.preci > flag.W))
//		return (NULL);
	if (flag.width <= 0 && flag.preci < 0)
		return (ft_nowinopr(str, flag, len));
	else if (flag.width <= 0 && flag.preci >= 0)
		return (ft_nowipr(str, flag, len));
	else if (flag.width > 0 && flag.preci < 0)
		return (ft_winopr(str, flag, len));
	else
		return (ft_wipr(str, flag, len));
}

spe_c	ft_special_c(char *str, flag_type flag)
{
	int		i;
	spe_c	spec;

	spec.len = 1;
	i = 0;
	flag = ft_flag_adjust(flag);
	if (flag.width > spec.len)
	{
		spec.tab = malloc(sizeof(char)* flag.width + 1);
		spec.tab[flag.width] = '\0';
		while (i < flag.width && flag.zero == 0)
		{
			spec.tab[i] = ' ';
			i++;
		}
		while (i < flag.width && flag.zero == 1)
		{
			spec.tab[i] = '0';
			i++;
		}
		if (flag.minus == 0)
			spec.tab[flag.width - 1] = str[0];
		else
			spec.tab[0] = str[0];
		spec.len = flag.width;
	}
	else
	{
		spec.tab = str;
//		free(str);
		return (spec);
	}
	return (spec);
}
