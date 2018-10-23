/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:46:59 by abytko            #+#    #+#             */
/*   Updated: 2017/12/02 17:06:41 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_c_w(char const *str, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			i++;
		}
		if (str[i] != c && str[i] != '\0')
			count++;
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	return (count);
}

static int			ft_c_ch(char const *s, char c)
{
	int count;

	count = 0;
	while (*s && *s++ != c)
		count++;
	return (count);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**fresh;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(fresh = (char **)malloc(sizeof(char *) * ft_c_w(s, c) + 8)))
		return (NULL);
	while (i < ft_c_w(s, c))
	{
		j = 0;
		while (s[k] == c && s[k] != '\0')
			k++;
		if (!(fresh[i] = (char *)malloc(sizeof(char) * ft_c_ch(&s[k], c) + 1)))
			return (NULL);
		while (s[k] != c && s[k] != '\0')
			fresh[i][j++] = s[k++];
		fresh[i][j] = '\0';
		i++;
	}
	fresh[i] = NULL;
	return (fresh);
}
