/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:49:27 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/17 16:50:18 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	char	*tab;

	if (!s1 || !s2)
		return (0);
	i = 0;
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	tab = (char *)malloc(sizeof(*tab) * (lens1 + lens2 + 1));
	if (!tab)
		return (0);
	while (i < lens1)
	{
		tab[i] = s1[i];
		i++;
	}
	while (i < lens1 + lens2)
	{
		tab[i] = s2[i - lens1];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
