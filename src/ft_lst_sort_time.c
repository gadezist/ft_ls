/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 14:47:33 by abytko            #+#    #+#             */
/*   Updated: 2018/03/22 18:39:54 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static int		ft_length(t_list_f *head)
{
	int			count;
	t_list_f	*current;

	count = 0;
	current = head;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

static void		ft_front_back_split(t_list_f *source, t_list_f **front,
									t_list_f **back)
{
	int			len;
	int			i;
	int			count;
	t_list_f	*current;

	i = 0;
	len = ft_length(source);
	current = source;
	count = (len - 1) / 2;
	if (len < 2)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		while (i++ < count)
			current = current->next;
		*front = source;
		*back = current->next;
		current->next = NULL;
	}
}

static t_list_f	*ft_sorted_merge(t_list_f *first, t_list_f *second)
{
	t_list_f *result;

	result = NULL;
	if (first == NULL)
		return (second);
	else if (second == NULL)
		return (first);
	if (first->st_mtimespec.tv_sec >= second->st_mtimespec.tv_sec)
	{
		result = first;
		result->next = ft_sorted_merge(first->next, second);
	}
	else
	{
		result = second;
		result->next = ft_sorted_merge(first, second->next);
	}
	return (result);
}

void			ft_merge_sort_mtime(t_list_f **list)
{
	t_list_f	*head;
	t_list_f	*first;
	t_list_f	*second;

	head = *list;
	if (head == NULL || head->next == NULL)
		return ;
	ft_front_back_split(head, &first, &second);
	ft_merge_sort_mtime(&first);
	ft_merge_sort_mtime(&second);
	*list = ft_sorted_merge(first, second);
}
