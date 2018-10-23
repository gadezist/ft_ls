/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abytko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 18:15:42 by abytko            #+#    #+#             */
/*   Updated: 2017/11/29 20:34:06 by abytko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	temp = *alst;
	if (alst && del)
	{
		while (temp)
		{
			*alst = temp;
			del(temp->content, temp->content_size);
			free(*alst);
			*alst = NULL;
			temp = temp->next;
		}
	}
}
