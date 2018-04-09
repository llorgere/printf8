/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 19:17:11 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 15:27:44 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int		i;
	int		val;

	i = 0;
	val = -1;
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	while (s1[i] == s2[i] && s2[i] != '\0' && s1[i] != '\0')
		i++;
	val = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (val);
}
