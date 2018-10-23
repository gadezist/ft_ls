/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_of_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:35:09 by abytko            #+#    #+#             */
/*   Updated: 2018/03/21 18:18:43 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

static char	*ft_permission(mode_t st_mode, char *path)
{
	char	*permiss;
	acl_t	acl;

	permiss = ft_strnew(11);
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	permiss[0] = S_ISDIR(st_mode) ? 'd' : '-';
	permiss[0] = S_ISLNK(st_mode) ? 'l' : permiss[0];
	permiss[0] = S_ISFIFO(st_mode) ? 'p' : permiss[0];
	permiss[0] = S_ISCHR(st_mode) ? 'c' : permiss[0];
	permiss[0] = S_ISBLK(st_mode) ? 'b' : permiss[0];
	permiss[0] = S_ISSOCK(st_mode) ? 's' : permiss[0];
	permiss[1] = st_mode & S_IRUSR ? 'r' : '-';
	permiss[2] = st_mode & S_IWUSR ? 'w' : '-';
	permiss[3] = st_mode & S_IXUSR ? 'x' : '-';
	permiss[4] = st_mode & S_IRGRP ? 'r' : '-';
	permiss[5] = st_mode & S_IWGRP ? 'w' : '-';
	permiss[6] = st_mode & S_IXGRP ? 'x' : '-';
	permiss[7] = st_mode & S_IROTH ? 'r' : '-';
	permiss[8] = st_mode & S_IWOTH ? 'w' : '-';
	permiss[9] = st_mode & S_IXOTH ? 'x' : '-';
	permiss[9] = st_mode & S_ISVTX ? 't' : permiss[9];
	permiss[10] = acl ? '+' : ' ';
	listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0 ? permiss[10] = '@' : 0;
	free(acl);
	return (permiss);
}

char		*ft_get_time(struct timespec timespec)
{
	char	*time_res;
	time_t	time_now;

	time_now = time(NULL);
	if ((time_now - timespec.tv_sec > 15778463) ||
			(time_now - timespec.tv_sec < -15778463))
	{
		time_res = ft_strsub(ctime(&timespec.tv_sec), 4, 20);
		time_res[7] = ' ';
		ft_memcpy(&time_res[8], &time_res[16], 5);
	}
	else
		time_res = ft_strsub(ctime(&timespec.tv_sec), 4, 12);
	return (time_res);
}

t_list_f	*ft_lstnew_entry(char const *d_name, struct stat *entry_info,
							char *path_name)
{
	t_list_f	*newlist;

	if (!(newlist = (t_list_f *)malloc(sizeof(t_list_f))))
		return (NULL);
	if (d_name == NULL || entry_info == NULL)
		return (NULL);
	newlist->d_name = ft_strdup(d_name);
	newlist->path_name = ft_strdup(path_name);
	newlist->st_mode = entry_info->st_mode;
	newlist->st_nlink = entry_info->st_nlink;
	newlist->user_info = getpwuid(entry_info->st_uid);
	newlist->group_info = getgrgid(entry_info->st_gid);
	newlist->user_name = ft_strdup(newlist->user_info->pw_name);
	newlist->group_name = newlist->group_info->gr_name;
	newlist->st_atimespec = entry_info->st_atimespec;
	newlist->st_mtimespec = entry_info->st_mtimespec;
	newlist->st_ctimespec = entry_info->st_ctimespec;
	newlist->m_time = ft_get_time(newlist->st_mtimespec);
	newlist->st_size = entry_info->st_size;
	newlist->st_blocks = entry_info->st_blocks;
	newlist->st_blksize = entry_info->st_blksize;
	newlist->permission = ft_permission(newlist->st_mode, newlist->path_name);
	newlist->next = NULL;
	return (newlist);
}
