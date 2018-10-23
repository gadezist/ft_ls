/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:32:40 by abytko            #+#    #+#             */
/*   Updated: 2017/12/02 17:04:47 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	start;
	size_t			len;
	char			*fresh;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
	{
		start++;
	}
	if (s[start])
	{
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		{
			len--;
		}
	}
	if (!(fresh = (char *)malloc(sizeof(char) * (len - start) + 1)))
		return (NULL);
	fresh = ft_strsub(s, start, (len + 1 - start));
	return (fresh);
}
