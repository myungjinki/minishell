/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:56:32 by sehan             #+#    #+#             */
/*   Updated: 2021/05/13 19:10:17 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	mini_init(t_mini *mini, char *envp[])
{
	write(1, ">", 1);
	mini->env = NULL;
	mini->history = NULL;
	ft_envp_lstinit(&mini->env, envp);
	ft_d_lstadd(&mini->history);
	mini->head = mini->history;
	term_set();
	mini->str = (char *)malloc(5);
	ft_memset(mini->str, 0, 5);
}
