/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 13:25:18 by abytko            #+#    #+#             */
/*   Updated: 2017/12/01 18:28:11 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *fresh;

	if (!(fresh = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero(fresh, size + 1);
	return (fresh);
}
