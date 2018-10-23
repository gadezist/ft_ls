/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartynu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 11:01:14 by vmartynu          #+#    #+#             */
/*   Updated: 2018/03/22 18:40:18 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void		ft_print_t(t_maxlen *max_width, int row, t_list_f *lst, int col)
{
	int			i;
	int			temp_row;
	int			j;
	t_list_f	*temp;

	temp_row = row;
	while (temp_row--)
	{
		i = 0;
		j = 0;
		while (i++ < col)
		{
			if (j < max_width->count)
			{
				temp = ft_get_index_lst(&lst, j);
				if (temp)
					ft_printf("%-*s", (max_width->len_name + 1), temp->d_name);
			}
			j += row;
		}
		ft_putchar('\n');
		lst = lst->next;
	}
}

void			ft_show_tab(t_list_f *list)
{
	t_maxlen		max_width;
	struct ttysize	width_term;
	unsigned long	width;
	int				col;

	ioctl(0, TIOCGWINSZ, &width_term);
	max_width = ft_maxlen(&list);
	width = max_width.len_name + 1;
	while (width < width_term.ts_cols - (max_width.len_name + 1)
			&& width != (max_width.len_name + 1) * max_width.count)
		width += (max_width.len_name + 1);
	col = width / (max_width.len_name + 1);
	(max_width.count % col == 0) ?
		ft_print_t(&max_width, max_width.count / col, list, col) :
			ft_print_t(&max_width, max_width.count / col + 1, list, col);
}
