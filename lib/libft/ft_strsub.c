/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:55:31 by abytko            #+#    #+#             */
/*   Updated: 2017/12/01 18:57:38 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(fresh = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- && s[start] != '\0')
	{
		fresh[i++] = s[start++];
	}
	fresh[i] = '\0';
	return (fresh);
}
