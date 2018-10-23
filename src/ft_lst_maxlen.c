/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_maxlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 20:54:23 by abytko            #+#    #+#             */
/*   Updated: 2018/03/05 21:40:18 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_lst_maxlen(t_list_f **list)
{
	t_list_f	*temp;
	size_t		maxlen;

	maxlen = 0;
	temp = *list;
	while (temp)
	{
		if (maxlen < temp->d_len)
			maxlen = temp->d_len;
		temp = temp->next;
	}
	return ((int)maxlen);
}
