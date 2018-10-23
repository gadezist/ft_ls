/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:14:42 by abytko            #+#    #+#             */
/*   Updated: 2017/12/01 15:16:36 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	temp1 = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		i++;
		if (*temp2 == (unsigned char)c)
		{
			*temp1 = *temp2;
			return (dest + i);
		}
		*temp1++ = *temp2++;
	}
	return (NULL);
}
