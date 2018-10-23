/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:37:33 by abytko            #+#    #+#             */
/*   Updated: 2018/03/23 16:07:06 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../lib/libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int				ft_printf(const char *format, ...);
const char		*ft_precision(const char *format, char **str);
const char		*ft_width(const char *format, char **str, char ch);
const char		*ft_flag(const char *format, char **str, char c, int delta);
char			*ft_string_and_char(va_list arg, const char *ch);
char			*ft_decimal_arg(va_list arg, const char *ch);
char			*ft_nondecimal_arg(va_list arg, const char *ch);
int				ft_widechar(wchar_t value, const char *ch);
int				ft_stringwidechar(wchar_t *arg, const char *ch);
char			*ft_flagplus(char *temp, char c, int delta);
char			*ft_flagoctotorp(char *temp, char c, int delta, char *fl);
char			*ft_flagzero(char *temp, char c, int delta);
char			*ft_flagminus(char *temp, char c, int delta, char *fl);
char			*ft_flagspace(char *temp, char c, int delta, char *fl);
char			*ft_flagoctotorp(char *temp, char c, int delta, char *fl);
int				ft_widthwide(const char *ch);

#endif
