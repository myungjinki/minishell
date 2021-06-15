/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:31:13 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 21:43:50 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(t_mini *mini, char **temp)
{
	ft_d_lstclear(&mini->head);
	ft_envp_lstclear(&mini->env);
	free(mini->str);
	if (temp)
	{
		if (temp[1][0] < '0' || temp[1][0] > '9')
		{
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(temp[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
			exit(255);
		}
		exit(ft_atoi(temp[1]));
	}
	else
		exit(0);
}
