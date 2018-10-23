/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:49:18 by abytko            #+#    #+#             */
/*   Updated: 2018/02/12 20:04:56 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_flagplus(char *temp, char c, int delta)
{
	size_t	len;
	char	*fresh;

	fresh = NULL;
	len = ft_strlen(temp);
	if (!(ft_strchr(temp, '-')) && (c == 'd' || c == 'i'))
	{
		if (delta < 0 && temp[-delta - 1] == ' ')
			temp[-delta - 1] = '+';
		else if (delta < 0)
			temp[0] = '+';
		else
		{
			fresh = ft_strnew(len + 1);
			ft_memcpy(fresh + 1, temp, len);
			*fresh = '+';
			free(temp);
			return (fresh);
		}
	}
	return (temp);
}

char		*ft_flagzero(char *temp, char c, int delta)
{
	size_t	len;

	len = ft_strlen(temp);
	if (c == 'd' || c == 'i' || c == 'u' || c == 'o' || c == 'x' || c == '%'
		|| c == 'X' || c == 'D' || c == 'O' || c == 'U' || c == 's' || c == 'c')
	{
		if (delta < 0)
			ft_memset(temp, '0', -delta);
	}
	if (temp[-delta] == '-' && delta < 0)
	{
		temp[0] = '-';
		temp[-delta] = '0';
	}
	return (temp);
}

char		*ft_flagminus(char *temp, char c, int delta, char *fl)
{
	size_t	len;
	char	*sign;

	sign = NULL;
	len = ft_strlen(temp);
	delta = (delta == 0 && c == 'p') ? delta - 2 : delta;
	if (c == 'd' || c == 'i' || c == 'u' || c == 'D' || c == 'U' || c == '%')
	{
		if (delta < -1)
		{
			if ((sign = ft_strchr(temp, '+')))
				ft_memswitch(temp, sign, len + delta + 1);
			else
				ft_memswitch(temp, temp - delta, len + delta);
		}
		else
			ft_memswitch(temp, temp - delta, len + delta);
	}
	else if (((c == 'x' || c == 'X') && fl[1] == '#') || c == 'p')
		ft_memswitch(temp, (temp - delta - 2), len + delta + 2);
	else if ((c == 'o' || c == 'O') && fl[1] == '#')
		ft_memswitch(temp, (temp - delta - 1), len + delta + 1);
	else
		ft_memswitch(temp, temp - delta, len + delta);
	return (temp);
}

char		*ft_flagspace(char *temp, char c, int delta, char *fl)
{
	char	*fresh;
	size_t	len;

	len = ft_strlen(temp);
	if (c == 'd' || c == 'i')
	{
		if (temp[0] != '+' && temp[0] != '-' && delta < 0)
		{
			if (fl[3] == '-')
			{
				ft_memmove(temp + 1, temp, len + delta);
				temp[0] = ' ';
			}
			else
				temp[0] = ' ';
		}
		else if (temp[0] != '+' && temp[0] != '-' && delta == 0)
		{
			fresh = ft_strjoin(" ", temp);
			free(temp);
			return (fresh);
		}
	}
	return (temp);
}
