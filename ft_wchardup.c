/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:00:27 by llorgere          #+#    #+#             */
/*   Updated: 2017/06/17 16:50:08 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_wchardup_null()
{
	char	*tab;

	if(!(tab = malloc(sizeof(char)* 7)))
		return (NULL);
	tab[0] = '(';
	tab[1] = 'n';
	tab[2] = 'u';
	tab[3] = 'l';
	tab[4] = 'l';
	tab[5] = ')';
	tab[6] = '\0';
	return (tab);
}

char	*ft_wchardup(wchar_t *s, flag_type *flag)
{
	int		i;
	int		j;
	char	*moc;

	if (s == NULL)
		return (ft_wchardup_null());
	i = 0;
	j = 0;
//	printf("wchardup 1 flag.w est [%d]\n", flag->W);
	while (s[i] != '\0')
		i++;
	moc = (char*)malloc(sizeof(wchar_t) * (i));
	if (!moc)
		return (NULL);
	while (j < i)
	{
		if(s[j] > 255 && flag->W == -1)
		{
		//	printf("test du if boucle wchardup\n");
			flag->W = j;
		}
		moc[j] = s[j];
		j++;
	}
//	printf("wchardup 2 flag.w est [%d]\n", flag->W);
	moc[j] = '\0';
	return (moc);
}
