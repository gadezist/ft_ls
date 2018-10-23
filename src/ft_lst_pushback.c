/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:06:21 by abytko            #+#    #+#             */
/*   Updated: 2018/03/19 17:37:28 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lst_pushback(t_list_f **list, char const *d_name,
	struct stat *entry_info, char *path_name)
{
	t_list_f *push;

	push = *list;
	if (push)
	{
		while (push->next)
			push = push->next;
		push->next = ft_lstnew_entry(d_name, entry_info, path_name);
	}
	else
		*list = ft_lstnew_entry(d_name, entry_info, path_name);
}
