/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 02:28:07 by llorgere          #+#    #+#             */
/*   Updated: 2017/12/20 02:38:43 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

//char		*ft_strndup(const char *s, size_t n);
int			ft_two_l_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (9);
	else if (str[0] == 'u')
		return (10);
	else if (str[0] == 'o')
		return (11);
	else if (str[0] == 'x')
		return (12);
	else if (str[0] == 'X')
		return (13);
	else if (str[0] == 'c')
		return (14);
	else if (str[0] == 's')
		return (15);
	//cette partie pas sur du tout
	else if (str[0] == 'D')
		return (16);
	else if (str[0] == 'U')
		return (17);
	else if (str[0] == 'O')
		return (18);
	else 
		return (ft_one_conv(str));
/*	else
		return (0);*/
}

int			ft_three_h_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (26);
	else if (str[0] == 'u')
		return (27);
	else if (str[0] == 'o')
		return (28);
	else if (str[0] == 'x')
		return (29);
	else if (str[0] == 'X')
		return (30);
	else 
		return (ft_one_conv(str));
/*	else
		return (0);*/
}

int			ft_three_l_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (16);
	else if (str[0] == 'u')
		return (17);
	else if (str[0] == 'o')
		return (18);
	else if (str[0] == 'x')
		return (19);
	else if (str[0] == 'X')
		return (20);
	else 
		return (ft_one_conv(str));
/*	else
		return (0);*/
}

int			ft_two_h_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (21);
	else if (str[0] == 'u')
		return (22);
	else if (str[0] == 'o')
		return (23);
	else if (str[0] == 'x')
		return (24);
	else if (str[0] == 'X')
		return (25);
	else if (str[0] == 'D')
		return (9);
	else if (str[0] == 'U')
		return (10);
	else if (str[0] == 'O')
		return (11);
	else 
		return (ft_one_conv(str));
/*	else
		return (0);*/
}

int			ft_two_z_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (31);
	else if (str[0] == 'u')
		return (32);
	else if (str[0] == 'o')
		return (33);
	else if (str[0] == 'x')
		return (34);
	else if (str[0] == 'X')
		return (35);
/*	else
		return (0);
*/	else 
		return (ft_one_conv(str));
}

int			ft_two_j_conv(char *str)
{
	if (str[0] == 'd' || str[0] == 'i')
		return (36);
	else if (str[0] == 'u')
		return (37);
	else if (str[0] == 'o')
		return (38);
	else if (str[0] == 'x')
		return (39);
	else if (str[0] == 'X')
		return (40);
	else 
		return (ft_one_conv(str));
}

int			ft_one_conv(char *str)
{	
	if (str[0] == 'd' || str[0] == 'i')
		return (1);
	else if (str[0] == 'u')
		return (2);
	else if (str[0] == 'o')
		return (3);
	else if (str[0] == 'x')
		return (4);
	else if (str[0] == 'X')
		return (5);
	else if (str[0] == 'c')
		return (6);
	else if (str[0] == 's')
		return (7);
	else if (str[0] == 'p')
		return (8);
	else if (str[0] == 'D')
		return (9);
	else if (str[0] == 'U')
		return (10);
	else if (str[0] == 'O')
		return (11);
	else if (str[0] == 'C')
		return (14);
	else if (str[0] == 'S')
		return (15);
	else if (str[0] == '%')
		return (41);
	else
		return (0);
}

int		ft_two_conv(char *str)
{
	if (str[0] == 'l')
		return (ft_two_l_conv(str));
	else if (str[0] == 'h')
		return (ft_two_h_conv(str));
	else if (str[0] == 'z')
		return (ft_two_z_conv(str));
	else if (str[0] == 'j')
		return (ft_two_j_conv(str));
	else 
		return (0);
}

int		ft_three_conv(char *str)
{
	if (str[0] == 'l' && str[1] == 'l')
		return (ft_three_l_conv(str));
	else if (str[0] == 'h' && str[1] == 'h')
		return (ft_three_h_conv(str));
	else 
		return (0);
}

int			ft_what_conv(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len == 1)
		return (ft_one_conv(str));
	else if (len == 2)
		return (ft_two_conv(str));
	else if (len == 3)
		return (ft_three_conv(str));
	else
		return (0);
}

static	flag_type	ft_conv_adjust(flag_type flag)
{
/*	if(flag.h > 0 && (flag.z == 1 || flag.j == 1 || flag.l > 0))
		flag.h = 0;
*/	if (flag.j == 1)
	{
		flag.h = 0;
		flag.l = 0;
		flag.z = 0;
	}
	else if (flag.l == 2)
	{
		flag.h = 0;
		flag.z = 0;
	}
	else if(flag.z == 1)
	{
		flag.l = 0;
		flag.h = 0;
	}
	else if(flag.l == 1)
		flag.h = 0;
	else
		return (flag);
	return (flag);
}

static	int			ft_what_convn(flag_type flag, char *str)
{
//	printf("test de what_conv | str est [%s]\nles flags sont l : %d | h : %d | j : %d | z : %d |\n", str, flag.l, flag.h, flag.j, flag.z);
	flag = ft_conv_adjust(flag);
	if (flag.j == 1)
		return (ft_two_j_conv(str));
	else if(flag.l == 2)
		return (ft_three_l_conv(str));
	else if (flag.z == 1)
		return (ft_two_z_conv(str));
	else if (flag.l == 1)
		return (ft_two_l_conv(str));
	else if (flag.h == 1)
		return (ft_two_h_conv(str));
	else if(flag.h == 2)
		return (ft_three_h_conv(str));
	else
		return (ft_one_conv(str));
}

flag_type		ft_arg_conv(char *tab)
{
	int			i;
	int			tmp;
	flag_type	flag;
	/*	int		conv_num;
		int		width;
		int		preci;
		int		flag_minus;
		int		flag_plus;
		int		flag_dies;
		int		flag_zero;
		int		flag_space;
		int		flag_point;
		*/	
	char 	*tabpw;

	i = 1;
	tmp = 0;
	flag.conv_num = 0;
	flag.width = -1;
	flag.preci = -1;
	flag.minus = 0;
	flag.plus = 0;
	flag.dies = 0;
	flag.zero = 0;
	flag.space = 0;
	flag.point = 0;
	flag.j = 0;
	flag.h = 0;
	flag.l = 0;
	flag.z = 0;
	flag.tab = NULL;
	flag.W = -1;

	while (tab[i] != 'd' && tab[i] != 'i' && tab[i] != 's' &&
			tab[i] != 'p' && tab[i] != 'S' && tab[i] !='D' &&
			tab[i] != 'U' && tab[i] !='O' && tab[i] != 'o' &&
			tab[i] != 'u' && tab[i] !='x' && tab[i] !='X' &&
			tab[i] != 'c' && tab[i] !='C'  && tab[i] !='\0'/* &&
			tab[i] != 'l' && tab[i] != 'j' && tab[i] != 'h' && tab[i] != 'z'*/ && tab[i] != '%')
	{
		if (tab[i] == '-' && flag.minus == 0 && flag.width < 0 && flag.preci < 0)
		{
			flag.minus++;
			i++;
		}
		else if (tab[i] == '+' && flag.plus == 0/* && flag.width < 0 && flag.preci < 0*/)
		{
			flag.plus++;
			i++;
		}
		else if (tab[i] == 'l' && flag.l < 2/* && flag.width < 0 && flag.preci < 0*/)
		{
			flag.l++;
			i++;
		}
		else if (tab[i] == 'h' && flag.h < 2/* && flag.width < 0 && flag.preci < 0*/)
		{
			flag.h++;
			i++;
		}
		else if (tab[i] == 'j' && flag.j == 0/* && flag.width < 0 && flag.preci < 0*/)
		{
			flag.j++;
			i++;
		}
		else if (tab[i] == 'z' && flag.z == 0/* && flag.width < 0 && flag.preci < 0*/)
		{
			flag.z++;
			i++;
		}
		else if (tab[i] == ' ' && flag.space == 0 && flag.width < 0 && flag.preci < 0)
		{
			flag.space++;
			i++;
		}
		else if (tab[i] == '0' && flag.zero == 0 && flag.width < 0 && flag.preci < 0)
		{
			flag.zero++;
			i++;
		}
		else if (tab[i] == '#' && flag.dies == 0 /*&& flag.width < 0 && flag.preci < 0*/)
		{
			flag.dies++;
			i++;
		}
		else if (tab[i] > '0' && tab[i] <= '9' && flag.width < 0 && flag.preci < 0)
		{
			tmp = i;
			while (tab[i] >= '0' && tab[i] <= '9')
				i++;
			tabpw = ft_strndup(tab + tmp, i - tmp + 1);
			flag.width = ft_atoi(tabpw);
			free(tabpw);
		}
		else if (tab[i] == '.' && flag.preci < 0)
		{
			if (tab[i + 1] < '0' || tab[i + 1] > '9')
			{
//				printf("test de la boucle 1\n");
				flag.preci = 0;
				i++;
			}
			else
			{
//				printf("test de la boucle 2\n");
				i++;
				tmp = i;
				while (tab[i] >= '0' && tab[i] <= '9')
					i++;
				tabpw = ft_strndup(tab + tmp, i - tmp + 1);
				flag.preci = ft_atoi(tabpw);
				free(tabpw);
			}
		}
		else if (tab[i] == '+' || tab[i] == ' ' || tab[i] == '#' || tab[i] == '-' || tab[i] == '0' || tab[i] == '.' || (tab[i] >= '0' && tab[i] <= '9') || tab[i] == 'j' || tab[i] == 'h' || tab[i] == 'l' || tab[i] == 'z')
		{
//			printf("test de la boucle 3\n");
			i++;
		}
		else
		{
			tmp = i;
			while (tab[i] != '\0')
				i++;
			if (tmp != i)
				flag.tab = ft_strndup(tab + tmp, i - tmp + 1);
			flag.conv_num = -1;
			return (flag);
		}
	}
		flag.conv_num = ft_what_convn(flag, tab + i);
		return (flag);
}
