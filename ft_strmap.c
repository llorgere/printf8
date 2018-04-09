/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:38:33 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 19:23:21 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*tab;

	if (!s || !f)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	tab = (char *)malloc(sizeof(char) * (i + 1));
	if (!tab)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		tab[i] = (*f)(s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
