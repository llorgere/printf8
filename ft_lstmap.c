/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llorgere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:56:31 by llorgere          #+#    #+#             */
/*   Updated: 2017/05/05 19:58:01 by llorgere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*tmp;
	t_list	*fresh;

	if (!lst || !f)
		return (0);
	if (!(fresh = (t_list *)malloc(sizeof(f(lst)))))
		return (0);
	fresh = f(lst);
	start = fresh;
	lst = lst->next;
	while (lst)
	{
		tmp = lst->next;
		if (!(fresh->next = (t_list *)malloc(sizeof(f(lst)))))
			return (0);
		fresh->next = f(lst);
		fresh = fresh->next;
		lst = tmp;
	}
	return (start);
}
