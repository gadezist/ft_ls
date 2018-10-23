/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:00:02 by abytko            #+#    #+#             */
/*   Updated: 2017/11/30 18:28:33 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t len)
{
	unsigned char *temp;
	unsigned char symb;

	temp = (unsigned char *)dest;
	symb = (unsigned char)c;
	while (len--)
	{
		*temp++ = symb;
	}
	return (dest);
}
