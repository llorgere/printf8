/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:14:56 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 15:17:51 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	*ft_memalloc(size_t size)
{
	size_t	*tab;
	size_t	i;

	tab = 0;
	i = 0;
	tab = (size_t*)malloc(sizeof(size_t) * (size));
	if (tab == 0)
		return (0);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
