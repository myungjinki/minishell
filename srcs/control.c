/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 13:08:08 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 13:47:28 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	control_d(t_mini *mini)
{
	if (ft_strcmp(mini->history->content, "") == 0)
	{
		printf("exit\n");
		ft_exit(mini, NULL);
	}
}

void	sig(int signo)
{
	backup_term(&g_mini);
	if (signo == SIGINT)
	{
		g_mini.flag = 130;
		free(g_mini.history->temp);
		free(g_mini.history->content);
		g_mini.history->temp = ft_strdup("");
		g_mini.history->content = ft_strdup("");
		g_mini.history = g_mini.head;
		if (g_mini.pid == 0)
			ft_putstr_fd("\nminishell$ ", 1);
	}
	else if (signo == SIGQUIT && g_mini.pid != 0)
	{
		g_mini.flag = 131;
		printf("Quit: 3\n");
	}
	term_set();
}
