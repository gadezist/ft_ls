/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagoctotorp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:09:11 by abytko            #+#    #+#             */
/*   Updated: 2018/02/13 14:27:12 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_octal(char *temp, int delta, size_t len)
{
	char *fresh;

	fresh = NULL;
	if (delta < 0)
		temp[-delta - 1] = '0';
	else
	{
		fresh = ft_strnew(len + 1);
		ft_memcpy(fresh + 1, temp, len);
		*fresh = '0';
		free(temp);
		return (fresh);
	}
	return (temp);
}

static char	*ft_xxp(char *temp, int delta, char c, char *fl)
{
	char	*fresh;

	if (delta < -1)
	{
		if (fl[0] == '0' && fl[3] != '-')
		{
			temp[0] = '0';
			temp[1] = (c != 'X') ? 'x' : 'X';
		}
		else
		{
			temp[-delta - 2] = '0';
			temp[-delta - 1] = (c != 'X') ? 'x' : 'X';
		}
	}
	else if (temp[0] != '\0' || c == 'p')
	{
		fresh = ft_strnew(ft_strlen(temp) + delta + 2);
		ft_memcpy(fresh + 2, temp, ft_strlen(temp));
		*fresh = '0';
		*(fresh + 1) = (c != 'X') ? 'x' : 'X';
		free(temp);
		return (fresh);
	}
	return (temp);
}

char		*ft_flagoctotorp(char *temp, char c, int delta, char *fl)
{
	size_t	len;
	char	*fresh;

	fresh = NULL;
	len = ft_strlen(temp);
	if (temp[len - 1] == '0' && fl[0] != '0' && fl[3] != '-' && c != 'p')
		return (temp);
	if ((c == 'o' || c == 'O') && temp[0] != '0')
		return (ft_octal(temp, delta, len));
	else if ((c == 'x' || c == 'X' || c == 'p'))
		return (ft_xxp(temp, delta, c, fl));
	return (temp);
}
