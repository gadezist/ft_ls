/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_total_blk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 18:59:13 by abytko            #+#    #+#             */
/*   Updated: 2018/03/14 12:54:43 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_total_blk(t_list_f **list)
{
	int			total;
	t_list_f	*temp;

	total = 0;
	temp = *list;
	while (temp)
	{
		total += temp->st_blocks;
		temp = temp->next;
	}
	return (total);
}
