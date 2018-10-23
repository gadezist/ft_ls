/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 21:37:32 by abytko            #+#    #+#             */
/*   Updated: 2018/03/23 17:38:14 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_lst_free(t_list_f *list)
{
	if (!list)
		return ;
	else
	{
		free(list->d_name);
		free(list->path_name);
		free(list->user_name);
		free(list->m_time);
		free(list->permission);
	}
}
