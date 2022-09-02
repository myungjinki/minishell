/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:35:43 by jachoi            #+#    #+#             */
/*   Updated: 2020/10/05 01:36:25 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *iter;
	t_list *next;

	iter = *lst;
	while (iter && del)
	{
		next = iter->next;
		ft_lstdelone(iter, del);
		iter = next;
	}
	*lst = 0;
}
