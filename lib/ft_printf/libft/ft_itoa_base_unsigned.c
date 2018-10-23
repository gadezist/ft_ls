/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_my.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 11:54:20 by abytko            #+#    #+#             */
/*   Updated: 2018/02/12 15:39:58 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	str_size(uintmax_t n, int base)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}

char		*ft_itoa_base_unsigned(uintmax_t num, int base)
{
	char			*str;
	int				len;
	uintmax_t		temp;

	len = str_size(num, base);
	temp = num;
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len--] = '\0';
	if (num == 0)
		str[len] = '0';
	while (temp > 0)
	{
		if ((temp % base) < 10)
			str[len--] = (char)((temp % base) + 48);
		else
			str[len--] = (char)(temp % base - 10 + 'a');
		temp = temp / base;
	}
	return (str);
}
