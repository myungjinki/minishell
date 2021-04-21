/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:29:53 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 19:41:53 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		t_f_lstclear(t_f_list **lst)
{
	t_f_list *temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
}

void		t_f_lstadd_back(t_f_list **lst)
{
	t_f_list *temp;

	if (!*lst)
	{
		*lst = (t_f_list *)malloc(sizeof(t_f_list));
		(*lst)->next = NULL;
		return ;
	}
	while ((*lst)->next)
		lst = &((*lst)->next);
	temp = (t_f_list *)malloc(sizeof(t_f_list));
	temp->next = NULL;
	(*lst)->next = temp;
}

t_f_list	*t_f_lstlast(t_f_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
