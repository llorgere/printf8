/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 15:30:57 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 19:01:09 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_itoa_min(int n)
{
	int		j;
	char	*tab;

	j = 0;
	if (!(tab = (char *)malloc(sizeof(*tab) * (12))))
		return (0);
	tab[0] = '-';
	tab[11] = '\0';
	tab[10] = '8';
	n = -(n / 10);
	j = 10;
	while (n > 0)
	{
		tab[j - 1] = (n % 10) + 48;
		n = n / 10;
		j--;
	}
	return (tab);
}

static char	*ft_itoa_malloc(int n, int j)
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

char		*ft_itoa(int n)
{
	int		i;
	int		j;

	i = n;
	j = 0;
	if (n == -2147483648)
		return (ft_itoa_min(n));
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
	return (ft_itoa_malloc(n, j));
}
