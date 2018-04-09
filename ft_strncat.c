/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 14:53:09 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 15:37:47 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	size_t		i;
	int			lend;

	i = 0;
	lend = 0;
	while (dest[lend] != '\0')
		lend++;
	while (i < nb && src[i])
	{
		dest[lend + i] = src[i];
		i++;
	}
	dest[lend + i] = '\0';
	return (dest);
}
