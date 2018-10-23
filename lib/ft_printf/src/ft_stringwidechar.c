/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringwidechar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:56:37 by abytko            #+#    #+#             */
/*   Updated: 2018/02/13 17:30:43 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_widthwidestring(wchar_t *arg, int width)
{
	int		size;
	int		i;
	char	*spacewidth;

	i = 0;
	size = 0;
	while (*(arg + i))
		size += ft_sizebyte_utf(*(arg + i++));
	spacewidth = ft_strnew(width - size);
	ft_putstr(ft_memset(spacewidth, ' ', width - size));
	free(spacewidth);
}

int			ft_stringwidechar(wchar_t *arg, const char *ch)
{
	int		size;
	int		i;
	int		width;
	wchar_t	*temp;

	i = 0;
	size = 0;
	temp = arg;
	if (!arg)
		return (write(1, "(null)", 6));
	width = ft_widthwide(ch);
	while (*(arg + i))
		size += ft_sizebyte_utf(*(arg + i++));
	while (*ch != '%')
		ch--;
	if ((width > size) && !ft_memchr(ch, '-', ft_strlench(ch, 'S')))
		ft_widthwidestring(arg, width);
	i = 0;
	while (*(arg + i))
		ft_widechar(*(arg + i++), ch);
	if ((width > size) && ft_memchr(ch, '-', ft_strlench(ch, 'S')))
		ft_widthwidestring(arg, width);
	if (width > size)
		return (size + (width - size));
	return (size);
}
