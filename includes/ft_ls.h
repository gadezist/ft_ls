/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:59:01 by abytko            #+#    #+#             */
/*   Updated: 2018/03/23 16:06:44 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include "../lib/libft/libft.h"
# include "ft_printf.h"
# include <dirent.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct			s_list_of_f
{
	char				*d_name;
	char				*path_name;
	size_t				d_len;
	mode_t				st_mode;
	nlink_t				st_nlink;
	struct passwd		*user_info;
	struct group		*group_info;
	char				*user_name;
	char				*group_name;
	struct timespec		st_atimespec;
	struct timespec		st_mtimespec;
	struct timespec		st_ctimespec;
	char				*m_time;
	off_t				st_size;
	quad_t				st_blocks;
	u_long				st_blksize;
	char				*permission;
	struct s_list_of_f	*next;
}						t_list_f;
typedef struct			s_maxlen
{
	int					count;
	size_t				len_name;
	int					len_nlink;
	size_t				len_username;
	size_t				len_groupname;
	int					len_size;
}						t_maxlen;
t_list_f				*ft_lstnew_entry(char const *d_name,
						struct stat *entry_info, char *path_name);
int						ft_lst_maxlen(t_list_f **list);
void					ft_lst_pushback(t_list_f **list, char const *d_name,
						struct stat *entry_info, char *path_name);
void					ft_merge_sort(t_list_f **list);
void					ft_print_list(t_list_f **list, char *flags);
void					ft_lst_rev(t_list_f **list);
void					ft_merge_sort_mtime(t_list_f **list);
int						ft_intlen(uintmax_t num);
int						ft_total_blk(t_list_f **list);
t_maxlen				ft_maxlen(t_list_f **list);
void					ft_getdir(DIR *dir, char *the_dir, char *flags);
void					ft_show_tab(t_list_f *list);
t_list_f				*ft_get_index_lst(t_list_f **list, int index);
void					ft_lst_free(t_list_f *list);
void					ft_print_file_err(char **argv, char *flags,
						int i, int argc);

#endif
