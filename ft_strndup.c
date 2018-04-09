/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:00:27 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/08 18:53:11 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	j;
	char	*moc;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	if (i < n)
	{
		moc = (char*)malloc(sizeof(*moc) * (n + 1));
		if (!moc)
			return (NULL);
	}
	else
	{
		moc = (char*)malloc(sizeof(*moc) * (i + 1));
		if (!moc)
			return (NULL);
	}
	while (j < i && j < n)
	{
		moc[j] = s[j];
		j++;
	}
	moc[j] = '\0';
	return (moc);
}
