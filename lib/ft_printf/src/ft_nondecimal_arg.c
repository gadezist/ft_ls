/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nondecimal_arg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:41:50 by abytko            #+#    #+#             */
/*   Updated: 2018/02/11 16:11:44 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static uintmax_t	ft_convert_type(va_list arg, const char *ch)
{
	unsigned char		argchar;
	unsigned short int	argshort;
	uintmax_t			argmax;

	if (*(ch - 1) == 'h' && (*(ch - 2) == 'h') && *ch != 'O')
		return (argchar = va_arg(arg, unsigned int));
	else if (*(ch - 1) == 'h' && *ch != 'O')
		return (argshort = va_arg(arg, unsigned int));
	else if (*(ch - 1) == 'l' && (*(ch - 2) == 'l'))
		return (argmax = va_arg(arg, unsigned long long int));
	else if (*(ch - 1) == 'l' || *ch == 'O')
		return (argmax = va_arg(arg, unsigned long int));
	else if (*(ch - 1) == 'j')
		return (argmax = va_arg(arg, uintmax_t));
	else if (*(ch - 1) == 'z')
		return (argmax = va_arg(arg, size_t));
	else
		return (0);
}

char				*ft_nondecimal_arg(va_list arg, const char *ch)
{
	uintmax_t	argmax_u;
	char		*argstr;
	int			i;

	i = -1;
	if (*ch == 'x' || *ch == 'X' || *ch == 'o' || *ch == 'O' || *ch == 'p')
	{
		if (*(ch - 1) == 'h' || *(ch - 1) == 'l' || *(ch - 1) == 'j'
				|| *(ch - 1) == 'z' || *ch == 'O')
			argmax_u = ft_convert_type(arg, ch);
		else if (*ch == 'p')
			argmax_u = va_arg(arg, uintmax_t);
		else
			argmax_u = va_arg(arg, unsigned int);
		if (*ch == 'x' || *ch == 'X' || *ch == 'p')
			argstr = ft_itoa_base_unsigned(argmax_u, 16);
		if (*ch == 'X')
			while (*(argstr + ++i))
				*(argstr + i) = ft_toupper(*(argstr + i));
		else if (*ch == 'o' || *ch == 'O')
			argstr = ft_itoa_base_unsigned(argmax_u, 8);
	}
	return (argstr);
}
