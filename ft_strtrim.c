/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 14:17:16 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 19:47:46 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_strtrim_malloc(int len, int i, char const *s)
{
	int		j;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	j = 0;
	while (j < len)
	{
		dest[j] = s[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;

	if (!s)
		return (0);
	i = 0;
	len = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == ' ')
		i++;
	len = ft_strlen(s + i);
	while ((s[i + len - 1] == '\n' || s[i + len - 1] == '\t' ||
				s[i + len - 1] == ' ') && len > 0)
		len--;
	return (ft_strtrim_malloc(len, i, s));
}
