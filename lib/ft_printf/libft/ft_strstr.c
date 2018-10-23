/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:17:04 by abytko            #+#    #+#             */
/*   Updated: 2017/11/22 18:28:39 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int temp;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		temp = i;
		while (big[temp++] == little[j++])
		{
			if (!little[j])
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
