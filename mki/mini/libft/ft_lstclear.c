/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 19:17:15 by sehan             #+#    #+#             */
/*   Updated: 2020/10/13 20:37:48 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
	}
}
