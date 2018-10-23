/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:19:47 by abytko            #+#    #+#             */
/*   Updated: 2017/11/30 20:04:51 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
		{
			while (i < len)
			{
				dest[i++] = '\0';
			}
		}
		i++;
	}
	return (dest);
}
