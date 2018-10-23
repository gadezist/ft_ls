/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:32:44 by abytko            #+#    #+#             */
/*   Updated: 2017/11/30 20:29:09 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	ldest;
	size_t	lsrc;

	i = 0;
	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	if (ldest >= size)
	{
		return (size + lsrc);
	}
	while (dest[i])
	{
		size--;
		i++;
	}
	j = 0;
	while (src[j] != '\0' && --size)
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (ldest + lsrc);
}
