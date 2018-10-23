/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigchar_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:58:04 by abytko            #+#    #+#             */
/*   Updated: 2018/02/13 17:30:41 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_size_eleven(wchar_t value)
{
	unsigned int	mask;
	unsigned int	temp;
	unsigned char	octet;

	mask = 49280;
	temp = value;
	octet = (mask >> 8) | ((temp >> 6) << 27) >> 27;
	ft_putchar(octet);
	octet = ((mask << 24) >> 24) | (temp << 26) >> 26;
	ft_putchar(octet);
	return (2);
}

static int	ft_size_sixteen(wchar_t value)
{
	unsigned int	mask;
	unsigned int	temp;
	unsigned char	octet;

	mask = 14712960;
	temp = value;
	octet = (mask >> 16) | ((temp >> 12) << 28) >> 28;
	ft_putchar(octet);
	octet = ((mask << 16) >> 24) | ((temp >> 6) << 26) >> 26;
	ft_putchar(octet);
	octet = ((mask << 24) >> 24) | (temp << 26) >> 26;
	ft_putchar(octet);
	return (3);
}

static int	ft_size_else(wchar_t value)
{
	unsigned int	mask;
	unsigned int	temp;
	unsigned char	octet;

	mask = 4034953344;
	temp = value;
	octet = (mask >> 24) | ((temp >> 18) << 29) >> 29;
	ft_putchar(octet);
	octet = ((mask << 8) >> 24) | ((temp >> 12) << 26) >> 26;
	ft_putchar(octet);
	octet = ((mask << 16) >> 24) | ((temp >> 6) << 26) >> 26;
	ft_putchar(octet);
	octet = ((mask << 24) >> 24) | (temp << 26) >> 26;
	ft_putchar(octet);
	return (4);
}

static void	ft_widthwidechar(int size, int width)
{
	char	*spacewidth;

	spacewidth = ft_strnew(width - size);
	ft_putstr(ft_memset(spacewidth, ' ', width - size));
	free(spacewidth);
}

int			ft_widechar(wchar_t value, const char *ch)
{
	int				width;
	unsigned char	octet;
	size_t			size;

	width = ft_widthwide(ch);
	size = ft_sizebyte_utf(value);
	while (*ch != '%')
		ch--;
	if (width > size && !ft_memchr(ch, '-', ft_strlench(ch, 'C')))
		ft_widthwidechar(size, width);
	if (size == 1)
		write(1, &value, 1);
	else if (size == 2)
		ft_size_eleven(value);
	else if (size == 3)
		ft_size_sixteen(value);
	else
		ft_size_else(value);
	if (width > size && ft_memchr(ch, '-', ft_strlench(ch, 'C')))
		ft_widthwidechar(size, width);
	if (width > size)
		return (size + (width - size));
	return (size);
}
