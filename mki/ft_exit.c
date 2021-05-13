/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:31:13 by sehan             #+#    #+#             */
/*   Updated: 2021/05/13 19:09:26 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(t_mini *mini, char *temp)
{
	printf("exit\n");
	ft_d_lstclear(&mini->head);
	ft_envp_lstclear(&mini->env);
	free(mini->str);
	free(temp);
	exit(0);
}
