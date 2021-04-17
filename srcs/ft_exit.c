/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:31:13 by sehan             #+#    #+#             */
/*   Updated: 2021/04/17 14:46:45 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(t_mini *mini, char *temp)
{
	ft_d_lstclear(&mini->head);
	ft_d_lstclear(&mini->history);
	ft_envp_lstclear(&mini->env);
	free(mini->str);
	free(temp);
	exit(0);
}
