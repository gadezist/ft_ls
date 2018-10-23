/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:13:40 by abytko            #+#    #+#             */
/*   Updated: 2018/03/19 18:21:22 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int g_i = 1;

static const char	*ft_return(const char *form, char **str, char ch, int width)
{
	char	*newstr;
	size_t	len;

	len = (ch == 'p') ? ft_strlen(*str) + 2 : ft_strlen(*str);
	while (*(form - g_i) == '0')
		(g_i)--;
	if (width == 0)
	{
		newstr = ft_strsub(form - g_i, 0, g_i);
		width = ft_atoi(newstr);
		free(newstr);
	}
	if (width <= (int)len || ch == 'S')
		return (form - g_i - 1);
	else
	{
		newstr = (ch != 0) ? ft_strnew(width) : ft_strnew(width--);
		ft_memset(newstr, ' ', width);
		len = (ch == 'p') ? len - 2 : len;
		ft_strcpy(newstr + (width - len), *str);
		free(*str);
		*str = newstr;
		return (form - g_i - 1);
	}
}

const char			*ft_width(const char *form, char **str, char ch, int width)
{
	while ((*(form - g_i) >= '0' && *(form - g_i) <= '9')
			|| *(form - g_i) == '*')
	{
		if (*(form - g_i - 1) == '%' || *(form - g_i - 1) == '-'
				|| *(form - g_i - 1) == '+' || *(form - g_i - 1) == '#'
				|| *(form - g_i - 1) == ' ' || *(form - g_i) == '*')
		{
			return (ft_return(form, str, ch, width - 1));
		}
		g_i++;
	}
	return (form);
}
