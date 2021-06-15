/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:59:01 by sehan             #+#    #+#             */
/*   Updated: 2021/06/14 22:03:43 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_add_export(t_mini *mini, char **temp)
{
	int i;

	i = 1;
	while (temp[i])
	{
		ft_envp_lstadd(&mini->env, temp[i]);
		i++;
	}
}
