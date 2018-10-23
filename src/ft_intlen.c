/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 12:52:14 by abytko            #+#    #+#             */
/*   Updated: 2018/03/14 12:52:24 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int	ft_intlen(uintmax_t num)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}
