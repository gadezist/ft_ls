/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:21:09 by abytko            #+#    #+#             */
/*   Updated: 2017/12/04 17:16:16 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pushback(t_list **list, void const *cont, size_t size)
{
	t_list *push;

	push = *list;
	if (push)
	{
		while (push->next)
			push = push->next;
		push->next = ft_lstnew(cont, size);
	}
	else
		*list = ft_lstnew(cont, size);
}
