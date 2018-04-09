/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:38:05 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 19:25:07 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*tab;

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
		tab[i] = (*f)(i, s[i]);
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
