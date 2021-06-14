/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 10:56:32 by sehan             #+#    #+#             */
/*   Updated: 2021/05/28 17:07:43 by sehan            ###   ########.fr       */
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
	mini->cm = tgetstr("cm", NULL);
	mini->ce = tgetstr("ce", NULL);
}
