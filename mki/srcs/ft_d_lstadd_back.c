/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_lstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:05:57 by sehan             #+#    #+#             */
/*   Updated: 2021/04/14 17:24:36 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_d_lstadd_back(t_d_list **lst, t_d_list *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		while ((*lst)->next)
			lst = &((*lst)->next);
		(*lst)->next = new;
		new->prev = *lst;
	}
}
