/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 17:34:29 by abytko            #+#    #+#             */
/*   Updated: 2017/11/30 20:08:35 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *append, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	j = 0;
	while (append[j] != '\0' && n--)
	{
		dest[i] = append[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
