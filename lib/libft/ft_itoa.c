/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:00:58 by abytko            #+#    #+#             */
/*   Updated: 2018/01/21 14:28:34 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int			ft_divider(int count)
{
	int div;

	if (count == 0)
		return (0);
	div = 1;
	while (count > 1)
	{
		div = div * 10;
		count--;
	}
	return (div);
}

static char			*ft_num(char *s, unsigned int t, int d, int i)
{
	while (d)
	{
		s[i++] = t / d + '0';
		t = t - (t / d) * d;
		d = d / 10;
	}
	s[i] = '\0';
	return (s);
}

char				*ft_itoa(int n)
{
	char			*number;
	int				i;
	int				div;
	unsigned int	temp;

	i = 0;
	div = ft_divider(ft_count(n));
	if (n < 0)
	{
		if (!(number = (char *)malloc(sizeof(char) * ft_count(n) + 2)))
			return (NULL);
		number[i++] = '-';
		temp = -n;
	}
	else
	{
		if (!(number = (char *)malloc(sizeof(char) * ft_count(n) + 1)))
			return (NULL);
		temp = n;
	}
	number = ft_num(number, temp, div, i);
	return (number);
}
