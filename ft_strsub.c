/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:45:56 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 19:37:31 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	i;

	if (!s)
		return (0);
	i = 0;
	tab = (char *)malloc(sizeof(char) * (len + 1));
	if (!tab)
		return (0);
	while (s[start] != '\0' && i < len)
	{
		tab[i] = s[start];
		start++;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
