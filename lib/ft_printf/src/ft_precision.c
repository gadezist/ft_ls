/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:28:21 by abytko            #+#    #+#             */
/*   Updated: 2018/03/20 13:19:53 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static const char	*ft_prec_condit(const char *frm, char **str, int n, int *i)
{
	char	*newstr;
	char	*temp;
	char	*minus;

	temp = *str;
	if (n <= (int)ft_strlen(temp) && *frm == 's')
		newstr = ft_strsub(temp, 0, n);
	else if (n > (int)ft_strlen(temp) && (*frm == 'd' || *frm == 'i' ||
	*frm == 'u' || *frm == 'x' || *frm == 'X' || *frm == 'o' || *frm == 'p'))
	{
		ft_strcpy((newstr = ft_strnew(n)) + (n - (int)ft_strlen(temp)), temp);
		ft_memset(newstr, '0', (n - (int)ft_strlen(temp)));
		if ((minus = ft_strchr(newstr, '-')))
		{
			newstr[0] = '-';
			ft_memset(minus, '0', 1);
		}
	}
	else if (n == 0 && *str[0] == '0')
		newstr = ft_strdup("");
	else
		return (frm - *i - 1);
	*str = newstr;
	free(temp);
	return (frm - *i - 1);
}

const char			*ft_precision(const char *frm, char **s, int precis)
{
	char	*temp;
	int		i;
	int		num;
	char	*prec;

	i = 1;
	temp = *s;
	while ((((*(frm - i) >= '0' && *(frm - i) <= '9')
				|| *(frm - i) == '.') && *frm != '%') || *(frm - i) == '*')
	{
		if (*(frm - i - 1) == '.')
		{
			prec = ft_strsub(frm - i, 0, i);
			num = (ft_strchr(temp, '-')) ? ft_atoi(prec) + 1 : ft_atoi(prec);
			num = (precis != 0) ? precis - 1 : num;
			free(prec);
			return (ft_prec_condit(frm, s, num, &i));
		}
		if ((*(frm - i++) == '.') && (**s == '0' || *frm == 's' || *frm == 'c'))
		{
			*s = ft_strdup("");
			return (frm - 1);
		}
	}
	return (frm);
}
