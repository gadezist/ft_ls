/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index_lst.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:53:31 by abytko            #+#    #+#             */
/*   Updated: 2018/03/16 18:35:10 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_list_f	*ft_get_index_lst(t_list_f **list, int index)
{
	t_list_f *temp;

	if (!list)
		return (NULL);
	temp = *list;
	if (temp)
	{
		while (index-- && temp)
		{
			temp = temp->next;
		}
	}
	return (temp);
}
