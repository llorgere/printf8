/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 16:09:42 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/08 18:51:35 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tab;

	if (!(tab = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		tab->content = NULL;
		tab->content_size = 0;
	}
	else
	{
		if (!(tab->content = malloc(content_size)))
			return (NULL);
		tab->content = ft_memcpy(tab->content, content, content_size);
		tab->content_size = content_size;
	}
	tab->next = NULL;
	return (tab);
}
