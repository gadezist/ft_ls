/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:59:21 by abytko            #+#    #+#             */
/*   Updated: 2017/12/01 14:57:23 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t len;

	len = ft_strlen(str);
	while (str[len] != c)
	{
		if (!len)
			return (NULL);
		len--;
	}
	return ((char *)(str + len));
}
