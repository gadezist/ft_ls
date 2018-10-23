/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:53:28 by abytko            #+#    #+#             */
/*   Updated: 2018/03/22 16:54:16 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_maxlen	ft_maxlen(t_list_f **list)
{
	t_maxlen maxlen;
	t_list_f *temp;

	temp = *list;
	maxlen.count = 0;
	maxlen.len_name = 0;
	maxlen.len_nlink = 0;
	maxlen.len_username = 0;
	maxlen.len_groupname = 0;
	maxlen.len_size = 0;
	while (temp && ++maxlen.count)
	{
		if (maxlen.len_name < ft_strlen(temp->d_name))
			maxlen.len_name = ft_strlen(temp->d_name);
		if (maxlen.len_nlink < ft_intlen(temp->st_nlink))
			maxlen.len_nlink = ft_intlen(temp->st_nlink);
		if (maxlen.len_username < ft_strlen(temp->user_name))
			maxlen.len_username = ft_strlen(temp->user_name);
		if (maxlen.len_groupname < ft_strlen(temp->group_name))
			maxlen.len_groupname = ft_strlen(temp->group_name);
		if (maxlen.len_size < ft_intlen(temp->st_size))
			maxlen.len_size = ft_intlen(temp->st_size);
		temp = temp->next;
	}
	return (maxlen);
}
