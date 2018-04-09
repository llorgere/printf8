/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:29:02 by llorgere          #+#    #+#             */
/*   Updated: 2017/04/14 17:21:56 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strncpypf(char *dest, char *src, size_t n, size_t m)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		dest[i] = src[i];
		i++;
		n--;
		m--;
	}
	while (m > 0)
	{
		dest[i] = '\0';
		i++;
		m--;
	}
	return (dest);
}
