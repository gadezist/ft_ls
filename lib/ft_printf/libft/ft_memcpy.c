/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:46:06 by abytko            #+#    #+#             */
/*   Updated: 2017/12/01 15:16:07 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!dest && !src)
		return (NULL);
	temp1 = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	while (n--)
	{
		*temp1++ = *temp2++;
	}
	return (dest);
}
