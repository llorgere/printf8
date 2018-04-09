/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:13:53 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/08 17:42:31 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*ump;

	i = 0;
	tmp = (unsigned char *)dest;
	ump = (unsigned char *)src;
	while (i < n)
	{
		tmp[i] = ump[i];
		if (ump[i] == (unsigned char)c)
			return (&(tmp[i + 1]));
		i++;
	}
	return (NULL);
}
