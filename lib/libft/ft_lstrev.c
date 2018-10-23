/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 17:06:50 by abytko            #+#    #+#             */
/*   Updated: 2017/12/04 17:16:06 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **list)
{
	t_list *curr;
	t_list *next;

	curr = (*list)->next;
	(*list)->next = NULL;
	while (curr)
	{
		next = curr->next;
		ft_lstadd(&(*list), curr);
		curr = next;
	}
}
