/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:14:27 by abytko            #+#    #+#             */
/*   Updated: 2018/03/16 19:02:30 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lst_rev(t_list_f **list)
{
	t_list_f	*current;
	t_list_f	*next;

	if (!list)
		return ;
	if (*list && (*list)->next)
	{
		current = (*list)->next;
		(*list)->next = NULL;
		while (current)
		{
			next = current->next;
			current->next = *list;
			*list = current;
			current = next;
		}
	}
}
