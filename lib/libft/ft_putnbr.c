/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 17:03:12 by abytko            #+#    #+#             */
/*   Updated: 2017/12/04 17:39:02 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_divider(unsigned int n)
{
	int div;

	if (n == 0)
		return (1);
	div = 1;
	while (n >= 10)
	{
		div = div * 10;
		n = n / 10;
	}
	return (div);
}

void		ft_putnbr(int n)
{
	unsigned int	temp;
	int				div;

	if (n < 0)
	{
		ft_putchar('-');
		temp = -n;
	}
	else
		temp = n;
	div = ft_divider(temp);
	while (div)
	{
		ft_putchar(temp / div + 48);
		temp = temp - (temp / div) * div;
		div = div / 10;
	}
}
