/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:59:20 by abytko            #+#    #+#             */
/*   Updated: 2017/11/30 15:36:05 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fresh;
	t_list *temp;

	if (lst && f)
	{
		temp = f(lst);
		fresh = temp;
		while (lst->next)
		{
			lst = lst->next;
			temp->next = f(lst);
			temp = temp->next;
		}
		temp->next = NULL;
		return (fresh);
	}
	return (NULL);
}
