/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:03:35 by abytko            #+#    #+#             */
/*   Updated: 2017/11/30 19:40:21 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)arr1)[i] == ((unsigned char *)arr2)[i])
		{
			i++;
		}
		else
		{
			return (((unsigned char *)arr1)[i] - ((unsigned char *)arr2)[i]);
		}
	}
	return (0);
}
