/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 16:11:18 by abytko            #+#    #+#             */
/*   Updated: 2018/02/12 15:18:48 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static intmax_t		ft_convert_type_signed(va_list arg, const char *ch)
{
	char		argchar;
	short int	argshort;
	intmax_t	argmax;

	if (*(ch - 1) == 'h' && (*(ch - 2) == 'h') && *ch != 'D')
		return (argchar = va_arg(arg, int));
	else if (*(ch - 1) == 'h' && *ch != 'D')
		return (argshort = va_arg(arg, int));
	else if (*(ch - 1) == 'l' && (*(ch - 2) == 'l'))
		return (argmax = va_arg(arg, long long int));
	else if (*(ch - 1) == 'l' || *ch == 'D')
		return (argmax = va_arg(arg, long int));
	else if (*(ch - 1) == 'j')
		return (argmax = va_arg(arg, intmax_t));
	else if (*(ch - 1) == 'z')
		return (argmax = va_arg(arg, size_t));
	else
		return (0);
}

static uintmax_t	ft_convert_type_unsigned(va_list arg, const char *ch)
{
	unsigned char			argchar;
	unsigned short int		argshort;
	unsigned long			argmax;

	if (*(ch - 1) == 'h' && (*(ch - 2) == 'h') && *ch != 'U')
		return (argchar = va_arg(arg, unsigned int));
	else if (*(ch - 1) == 'h' && *ch != 'U')
		return (argshort = va_arg(arg, unsigned int));
	else if (*(ch - 1) == 'l' && (*(ch - 2) == 'l'))
		return (argmax = va_arg(arg, unsigned long long int));
	else if (*(ch - 1) == 'l' || *ch == 'U')
		return (argmax = va_arg(arg, unsigned long int));
	else if (*(ch - 1) == 'j')
		return (argmax = va_arg(arg, uintmax_t));
	else if (*(ch - 1) == 'z')
		return (argmax = va_arg(arg, size_t));
	else
		return (0);
}

char				*ft_decimal_arg(va_list arg, const char *ch)
{
	intmax_t	argintmax;
	uintmax_t	arguintmax;
	char		*argstr;

	if (*ch == 'd' || *ch == 'i' || *ch == 'D')
	{
		if (*(ch - 1) == 'h' || *(ch - 1) == 'l' || *(ch - 1) == 'j'
				|| *(ch - 1) == 'z' || *ch == 'D')
			argintmax = ft_convert_type_signed(arg, ch);
		else
			argintmax = va_arg(arg, int);
		argstr = ft_itoa_base_signed(argintmax, 10);
	}
	if (*ch == 'u' || *ch == 'U')
	{
		if (*(ch - 1) == 'h' || *(ch - 1) == 'l' || *(ch - 1) == 'j'
				|| *(ch - 1) == 'z' || *ch == 'U')
			arguintmax = ft_convert_type_unsigned(arg, ch);
		else
			arguintmax = va_arg(arg, unsigned int);
		argstr = ft_itoa_base_unsigned(arguintmax, 10);
	}
	return (argstr);
}
