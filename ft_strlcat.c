/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:39:31 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 15:42:29 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lend;
	size_t	lens;

	i = 0;
	lend = 0;
	lens = 0;
	while (dest[lend] != '\0')
		lend++;
	while (src[lens] != '\0')
		lens++;
	if (lend >= size)
		return (size + lens);
	while (i < (size - 1 - lend) && src[i] != '\0')
	{
		dest[lend + i] = src[i];
		i++;
	}
	dest[lend + i] = '\0';
	if (size == 0)
		return (lens);
	return (lend + lens);
}
