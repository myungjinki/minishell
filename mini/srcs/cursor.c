/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:16:13 by sehan             #+#    #+#             */
/*   Updated: 2021/05/31 14:48:10 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	arrow(t_mini *mini, t_d_list **lst, int flag)
{
	delete_end(mini, 1);
	if (flag == ARROW_UP)
	{
		if ((*lst)->next)
			*lst = (*lst)->next;
	}
	else
	{
		if ((*lst)->prev)
			*lst = (*lst)->prev;
	}
	ft_putstr_fd((*lst)->content, 1);
}
