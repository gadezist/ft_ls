/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 15:13:14 by abytko            #+#    #+#             */
/*   Updated: 2018/03/20 13:14:33 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int g_count;

static char	*ft_retarg(va_list arg, const char *ch)
{
	if (*ch == 's' || (*ch == 'c' && *(ch - 1) != 'l'))
		return (ft_string_and_char(arg, ch));
	else if (*ch == 'd' || *ch == 'i' || *ch == 'u' || *ch == 'D' || *ch == 'U')
		return (ft_decimal_arg(arg, ch));
	else if (*ch == 'x' || *ch == 'X' || *ch == 'o' || *ch == 'p' || *ch == 'O')
		return (ft_nondecimal_arg(arg, ch));
	return ("");
}

static int	ft_vaarg(va_list argptr, const char **form, char **str)
{
	int wildcard;

	wildcard = 0;
	while (**form)
	{
		(*form)++;
		if (**form == '*')
			wildcard = va_arg(argptr, int);
		if (**form == 's' || **form == 'i' || **form == 'd' || **form == 'c'
			|| **form == 'u' || **form == 'x' || **form == 'X' || **form == 'o'
			|| **form == 'p' || **form == 'D' || **form == 'O' || **form == 'U'
			|| **form == 'C' || **form == 'S' || **form == '%')
		{
			if (**form == 'C' || (**form == 'c' && *(*form - 1) == 'l'))
				g_count += ft_widechar(va_arg(argptr, wchar_t), *form);
			else if (**form == 'S' || (**form == 's' && *(*form - 1) == 'l'))
				g_count += ft_stringwidechar(va_arg(argptr, wchar_t *), *form);
			else if (**form == '%')
				*str = ft_strdup("%");
			else
				*str = ft_retarg(argptr, *form);
			return (wildcard + 1);
		}
	}
	return (wildcard);
}

static void	ft_formating(const char *format, char *str, char ch, int wildcard)
{
	const char	*temp;
	size_t		len;

	temp = format;
	format = ft_precision(format, &str, wildcard - 1);
	len = ft_strlen(str);
	format = ft_width(format, &str, ch, wildcard);
	format = ft_flag(format, &str, *temp, len - ft_strlen(str));
	ft_putstr(str);
	free(str);
	if (ch == 0)
		g_count += write(1, "\0", 1);
	g_count += ft_strlen(str);
}

static void	ft_format(va_list argptr, const char **format, char **str)
{
	char	ch;
	int		wildcard;

	wildcard = ft_vaarg(argptr, format, str);
	if (wildcard)
		ch = (**format == 'c' && *(*format - 1) != 'l') ? **str : **format;
	if (*str)
		ft_formating(*format, *str, ch, wildcard);
	if (!*str && **format != 'S' && **format != 'C'
			&& *(*format - 1) != 'l')
		g_count += write(1, "(null)", 6);
}

int			ft_printf(const char *format, ...)
{
	va_list		argptr;
	char		*str;
	const char	*temp;

	g_count = 0;
	temp = format;
	va_start(argptr, format);
	while (*temp)
	{
		str = NULL;
		format = temp;
		if (*format != '%' && ++g_count)
			ft_putchar(*format);
		if (*format == '%')
			ft_format(argptr, &format, &str);
		temp = format;
		temp = (*temp != '\0') ? temp + 1 : temp;
	}
	va_end(argptr);
	return (g_count);
}
