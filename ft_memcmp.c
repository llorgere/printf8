/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:39:19 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/08 18:29:22 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	int				val;
	unsigned char	*ts1;
	unsigned char	*ts2;

	i = 0;
	val = -1;
	ts1 = (unsigned char *)s1;
	ts2 = (unsigned char *)s2;
	if (!n)
		return (0);
	if ((ts1[i] == '\0' && ts2[i] == '\0') || n == 0)
		return (0);
	while (ts1[i] == ts2[i] && i < n - 1)
		i++;
	val = ts1[i] - ts2[i];
	return (val);
}
