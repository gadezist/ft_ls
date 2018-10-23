/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:56:22 by abytko            #+#    #+#             */
/*   Updated: 2018/03/23 12:18:12 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static void	ft_path(char *path_name, char *the_dir, char *name)
{
	ft_strncpy(path_name, the_dir, PATH_MAX);
	ft_strncat(path_name, "/", PATH_MAX);
	ft_strncat(path_name, name, PATH_MAX);
}

static void	ft_flag_recursive(char *the_dir, t_list_f *list_f,
							char *path_name, char *flags)
{
	DIR			*dir;
	t_list_f	*temp;

	while (list_f)
	{
		if (S_ISDIR(list_f->st_mode) && ft_strcmp(list_f->d_name, ".")
		&& ft_strcmp(list_f->d_name, ".."))
		{
			ft_putchar('\n');
			ft_path(path_name, the_dir, list_f->d_name);
			ft_printf("%s:\n", path_name);
			if ((dir = opendir(path_name)))
			{
				ft_getdir(dir, path_name, flags);
				closedir(dir);
			}
			else if (!dir && errno == EACCES)
				ft_printf("ls: %s: %s\n", list_f->d_name, strerror(errno));
		}
		ft_lst_free(list_f);
		temp = list_f;
		list_f = list_f->next;
		free(temp);
	}
}

void		ft_getdir(DIR *dir, char *the_dir, char *flags)
{
	char			path_name[PATH_MAX + 1];
	struct dirent	*entry;
	struct stat		entry_info;
	t_list_f		*list_f;

	list_f = NULL;
	while ((entry = readdir(dir)))
	{
		ft_path(path_name, the_dir, entry->d_name);
		if (((!(ft_strcmp(entry->d_name, "."))
			|| !(ft_strcmp(entry->d_name, "..")) || entry->d_name[0] == '.')
			&& !ft_strchr(flags, 'a')) && !ft_strchr(flags, 'f'))
			;
		else if (lstat(path_name, &entry_info) == 0)
			ft_lst_pushback(&list_f, entry->d_name, &entry_info, path_name);
	}
	if (!ft_strchr(flags, 'f'))
		ft_merge_sort(&list_f);
	ft_print_list(&list_f, flags);
	if (ft_strchr(flags, 'R'))
		ft_flag_recursive(the_dir, list_f, path_name, flags);
}
