/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:48:49 by abytko            #+#    #+#             */
/*   Updated: 2017/12/01 15:18:39 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	int i;
	int j;
	int temp;
	int templen;

	i = 0;
	if (!lit[i])
		return ((char *)big);
	while (len && big[i])
	{
		j = 0;
		temp = i;
		templen = len--;
		while (big[temp++] == lit[j++] && templen--)
		{
			if (!lit[j])
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
