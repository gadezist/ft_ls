/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:31:11 by abytko            #+#    #+#             */
/*   Updated: 2018/02/12 20:05:21 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_flaguniq(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strnew(6);
	ft_memset(temp, '1', 5);
	while (str[i])
	{
		if (str[i] == '0')
			temp[0] = '0';
		if (str[i] == '#')
			temp[1] = '#';
		if (str[i] == '+')
			temp[2] = '+';
		if (str[i] == '-')
			temp[3] = '-';
		if (str[i] == ' ')
			temp[4] = ' ';
		i++;
	}
	return (temp);
}

const char	*ft_flag(const char *format, char **str, char c, int delta)
{
	size_t	i;
	char	*temp;
	char	*fl;
	char	*flag;

	i = 0;
	temp = *str;
	delta = (delta > 0) ? 0 : delta;
	while (*(format - i) != '%')
		i++;
	format = format - i;
	flag = ft_strsub(format + 1, 0, i);
	fl = ft_flaguniq(flag);
	free(flag);
	i = 0;
	if (fl[0] == '0' && fl[3] != '-' &&
			!(ft_memchr(format, '.', ft_strlench(format, c))))
		temp = ft_flagzero(temp, c, delta);
	fl[1] == '#' || c == 'p' ? temp = ft_flagoctotorp(temp, c, delta, fl) : 0;
	fl[2] == '+' ? temp = ft_flagplus(temp, c, delta) : 0;
	fl[3] == '-' ? temp = ft_flagminus(temp, c, delta, fl) : 0;
	fl[4] == ' ' ? temp = ft_flagspace(temp, c, delta, fl) : 0;
	*str = temp;
	free(fl);
	return (format);
}
