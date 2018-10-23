/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 17:56:22 by abytko            #+#    #+#             */
/*   Updated: 2018/03/22 17:59:04 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		g_flags[11] = "-Rafglort1\0";

static char	*ft_flag_while(char *flags, unsigned int *k, char c)
{
	if (ft_strchr(g_flags, c))
	{
		if (*k > 0 && c == '-')
		{
			ft_printf("ft_ls: illegal option -- %c\n", c);
			ft_printf("%s\n", "usage: ft_ls [-Ralrt1] [file ...]");
			return (NULL);
		}
		flags[*k] = c;
		*k += 1;
		return (flags);
	}
	else
	{
		ft_printf("ft_ls: illegal option -- %c\n", c);
		ft_printf("%s\n", "usage: ft_ls [-Ralrt1] [file ...]");
		return (NULL);
	}
}

static char	*ft_flags(char **argv, unsigned int *i, int argc)
{
	char			*flags;
	unsigned int	j;
	unsigned int	k;

	k = 0;
	ft_bzero((flags = ft_strnew(10)), 10);
	while (*i < (unsigned int)argc && argv[*i][0] == '-')
	{
		j = 1;
		while (argv[*i][j] != '\0')
		{
			if (!(ft_flag_while(flags, &k, argv[*i][j])))
				return (NULL);
			j++;
		}
		if (argv[*i][1] == '\0')
			return (flags);
		*i += 1;
		if (argv[*i - 1][1] == '-')
			return (flags);
	}
	return (flags);
}

static void	ft_print_dir(char **argv, char *flags, unsigned int i, int argc)
{
	DIR	*dir;

	if (i + 1 < (unsigned int)argc)
	{
		while (i < (unsigned int)argc)
		{
			if ((dir = opendir(argv[i])))
			{
				ft_printf("%s:\n", argv[i]);
				ft_getdir(dir, argv[i], flags);
			}
			if (i + 1 != (unsigned int)argc && dir)
				ft_printf("\n");
			i++;
		}
	}
	else
	{
		if ((dir = opendir(argv[i])))
			ft_getdir(dir, argv[i], flags);
	}
	if (dir)
		closedir(dir);
}

int			main(int argc, char **argv)
{
	DIR				*dir;
	unsigned int	i;
	char			*flags;

	dir = NULL;
	i = 1;
	flags = "-";
	if ((unsigned int)argc > 1 && i <= (unsigned int)argc)
		if (argv[i][0] == '-')
			if (!(flags = ft_flags(argv, &i, argc)))
				return (1);
	if ((i == (unsigned int)argc) && (dir = opendir(".")))
		ft_getdir(dir, ".", flags);
	if (argc > 1)
		ft_print_file_err(argv, flags, i, argc);
	ft_print_dir(argv, flags, i, argc);
	if (dir)
		closedir(dir);
	return (0);
}
