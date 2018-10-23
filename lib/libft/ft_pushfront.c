/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushfront.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 16:51:33 by abytko            #+#    #+#             */
/*   Updated: 2017/12/04 17:22:04 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pushfront(t_list **list, void const *cont, size_t size)
{
	t_list *push;
	t_list *temp;

	temp = *list;
	if (temp)
	{
		push = ft_lstnew(cont, size);
		*list = push;
		push->next = temp;
	}
	else
		*list = ft_lstnew(cont, size);
}
