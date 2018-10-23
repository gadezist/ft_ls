/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizebyte.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 16:39:48 by abytko            #+#    #+#             */
/*   Updated: 2018/02/12 18:55:40 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_sizebyte_utf(wchar_t ch)
{
	size_t	len;
	char	*temp;

	temp = ft_itoa_base_unsigned(ch, 2);
	len = ft_strlen(temp);
	free(temp);
	if (len <= 7)
		return (1);
	if (len <= 11)
		return (2);
	if (len <= 16)
		return (3);
	else
		return (4);
}
