/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 13:24:38 by abytko            #+#    #+#             */
/*   Updated: 2017/12/27 14:16:15 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_flag(const char *str)
{
	if (str[0] == '-')
		return (-1);
	else
		return (1);
}

int			ft_atoi(const char *str)
{
	int					flag;
	int					i;
	unsigned long long	rez;

	i = 0;
	rez = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t') ||
		(str[i] == '\v' || str[i] == '\f' || str[i] == '\r'))
		i++;
	flag = ft_flag(&str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez = rez * 10;
		rez = rez + str[i] - 48;
		i++;
	}
	if (rez > 9223372036854775807 && flag == 1)
		return (-1);
	if (rez > 9223372036854775807 && flag == -1)
		return (0);
	return (rez * flag);
}
