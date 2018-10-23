/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_and_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 15:48:49 by abytko            #+#    #+#             */
/*   Updated: 2018/02/11 15:07:21 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_string_and_char(va_list arg, const char *ch)
{
	char			*argstr;
	unsigned char	argchar;

	if (*ch == 's')
	{
		argstr = va_arg(arg, char *);
		if (argstr)
			argstr = ft_strdup(argstr);
	}
	if (*ch == 'c')
	{
		argchar = va_arg(arg, int);
		argstr = ft_memset(ft_strnew(1), argchar, 1);
	}
	return (argstr);
}
