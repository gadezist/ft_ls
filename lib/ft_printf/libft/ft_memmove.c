/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:58:04 by abytko            #+#    #+#             */
/*   Updated: 2017/12/04 20:16:26 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t p;

	p = len;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (((unsigned char *)dst) <= ((unsigned char *)src))
	{
		while (len--)
		{
			*((unsigned char *)dst++) = *((unsigned char *)src++);
		}
		return (dst - p);
	}
	else
	{
		while (len--)
		{
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
		}
		return (dst);
	}
}
