/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:25:38 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 19:39:58 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_d_lstadd(t_d_list **lst)
{
	t_d_list *new;

	new = ft_d_lstnew(ft_strdup(""));
	if (!(*lst))
		*lst = new;
	else
	{
		(*lst)->prev = new;
		new->next = *lst;
		*lst = new;
	}
}
