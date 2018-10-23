/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_err.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:52:18 by abytko            #+#    #+#             */
/*   Updated: 2018/03/22 18:05:52 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_print_err(t_list_f *list, char *flags, int flag)
{
	if (list)
	{
		ft_merge_sort(&list);
		ft_print_list(&list, flags);
		if (flag)
			ft_printf("%c", '\n');
	}
}

static void	ft_notdir(t_list_f **list, char *path, struct stat *entry_info,
		char *flags)
{
	char *ch;

	if ((ch = ft_strchr(flags, 'l')))
		*ch = 'z';
	ft_lst_pushback(list, path, entry_info, path);
}

static void	ft_permiss_err(char *path, int i, int argc)
{
	char *name;

	if ((name = ft_strrchr(path, '/')))
		ft_printf("%s:\nft_ls: %s: %s\n", path, name + 1, strerror(errno));
	else
		ft_printf("%s:\nft_ls: %s: %s\n", path, path, strerror(errno));
	if (i + 1 != argc)
		ft_putchar('\n');
}

void		ft_print_file_err(char **argv, char *flags, int i,
		int argc)
{
	DIR			*dir;
	int			flag;
	t_list_f	*list_file;
	struct stat	entry_info;

	list_file = NULL;
	flag = 0;
	while (i < argc)
	{
		if (!(dir = opendir(argv[i])) && errno == ENOENT)
			ft_printf("ft_ls: %s: %s\n", argv[i], strerror(errno));
		else if (!dir && errno == ENOTDIR && lstat(argv[i], &entry_info) == 0)
			ft_notdir(&list_file, argv[i], &entry_info, flags);
		else if (!dir && errno == EACCES && argc == 2)
			ft_printf("ft_ls: %s: %s\n", argv[i], strerror(errno));
		else if (!dir && errno == EACCES)
			ft_permiss_err(argv[i], i, argc);
		else
			flag = 1;
		i++;
	}
	ft_print_err(list_file, flags, flag);
	if (dir)
		closedir(dir);
}
