/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthwide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:39:52 by abytko            #+#    #+#             */
/*   Updated: 2018/02/13 14:43:34 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_widthwide(const char *ch)
{
	int		i;
	int		width;
	char	*strwidth;

	width = 0;
	i = 1;
	while (*(ch - i) >= '0' && *(ch - i) <= '9')
	{
		if (*(ch - i - 1) == '%' || *(ch - i - 1) == '-'
			|| *(ch - i - 1) == '+' || *(ch - i - 1) == '#'
			|| *(ch - i - 1) == ' ')
		{
			strwidth = ft_strsub(ch - i, 0, i);
			width = ft_atoi(strwidth);
			free(strwidth);
		}
		i++;
	}
	return (width);
}
