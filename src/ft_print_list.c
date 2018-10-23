/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:57:03 by abytko            #+#    #+#             */
/*   Updated: 2018/03/22 17:59:51 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_print_link(t_list_f *list)
{
	int		len;
	char	linkbuf[PATH_MAX + 1];

	len = 0;
	if (list->permission[0] == 'l')
	{
		len = readlink(list->path_name, linkbuf, PATH_MAX);
		ft_printf(" -> %.*s\n", len + 1, linkbuf);
	}
	else
		ft_putchar('\n');
}

static void	ft_print_l(t_list_f *list, t_maxlen maxlen, char *flags)
{
	int		total;
	int		l_s;

	l_s = maxlen.len_size;
	total = ft_total_blk(&list);
	!ft_strchr(flags, 'z') ? ft_printf("total %d\n", total) : 0;
	while (list)
	{
		ft_printf("%s %*d ", list->permission, maxlen.len_nlink,
			list->st_nlink);
		if (!ft_strchr(flags, 'g'))
			ft_printf("%-*s  ", maxlen.len_username, list->user_name);
		if (!ft_strchr(flags, 'o'))
			ft_printf("%-*s  ", maxlen.len_groupname, list->group_name);
		ft_printf("%*d %s %s", l_s, list->st_size, list->m_time, list->d_name);
		ft_print_link(list);
		if (!ft_strchr(flags, 'R'))
		{
			ft_lst_free(list);
			free(list);
		}
		list = list->next;
	}
}

static void	ft_print_one(t_list_f *list, char *flags)
{
	if (!list)
		return ;
	while (list)
	{
		ft_printf("%s\n", list->d_name);
		if (!ft_strchr(flags, 'R'))
		{
			ft_lst_free(list);
			free(list);
		}
		list = list->next;
	}
}

static void	ft_print_tab(t_list_f *list, char *flags)
{
	t_list_f *tab_temp;

	tab_temp = list;
	ft_show_tab(list);
	if (!ft_strchr(flags, 'R'))
	{
		while (tab_temp)
		{
			ft_lst_free(tab_temp);
			free(tab_temp);
			tab_temp = tab_temp->next;
		}
	}
}

void		ft_print_list(t_list_f **list, char *flags)
{
	t_list_f	*temp;
	t_maxlen	maxlen;

	maxlen = ft_maxlen(list);
	if (ft_strchr(flags, 't'))
		ft_merge_sort_mtime(list);
	if (ft_strchr(flags, 'r'))
		ft_lst_rev(list);
	temp = *list;
	if (ft_strchr(flags, 'l') || ft_strchr(flags, 'z') || ft_strchr(flags, 'g')
			|| ft_strchr(flags, 'o'))
		ft_print_l(temp, maxlen, flags);
	else if (ft_strchr(flags, '1'))
		ft_print_one(temp, flags);
	else if (temp)
		ft_print_tab(temp, flags);
}
