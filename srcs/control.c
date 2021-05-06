/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:08:08 by sehan             #+#    #+#             */
/*   Updated: 2021/05/06 16:22:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	control_d(t_mini *mini)
{
	if (ft_strcmp(mini->lst_temp->content, "") == 0)
	{
		printf("exit\n");
		ft_exit(mini, NULL);
	}
}

void	sig(int signo)
{
	if (signo == SIGINT)
	{
		signo = 0;
		ft_d_lstclear(&g_mini.lst_temp);
		ft_d_lstcopy(&g_mini.lst_temp, g_mini.history);
		g_mini.head = g_mini.lst_temp;
		ft_putstr_fd("\n>", 1);
	}
	else if (signo == SIGQUIT && g_mini.pid != 0)
	{
		printf("^\\Quit: 3\n");
	}
}
