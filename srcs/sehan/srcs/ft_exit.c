/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:31:13 by sehan             #+#    #+#             */
/*   Updated: 2021/06/18 13:35:20 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	exit_free(t_mini *mini, int i)
{
	ft_d_lstclear(&mini->head);
	ft_envp_lstclear(&mini->env);
	free(mini->str);
	backup_term(mini);
	exit(i);
}

void		ft_exit(t_mini *mini, char **temp)
{
	if (temp && temp[1])
	{
		if (temp[2])
		{
			mini->status = 1;
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		}
		else if (temp[1][0] < '0' || temp[1][0] > '9')
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(temp[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit_free(mini, 255);
		}
		else
			exit_free(mini, ft_atoi(temp[1]));
	}
	else
		exit_free(mini, 0);
}
