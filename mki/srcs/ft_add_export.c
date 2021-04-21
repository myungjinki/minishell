/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:59:01 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 18:04:54 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_add_export(t_mini *mini, char *temp)
{
	char	**split;
	int		i;

	split = ft_split(temp, ' ');
	i = 1;
	while (split[i])
	{
		ft_envp_lstadd(&mini->env, split[i]);
		i++;
	}
	free_split(split);
	exit(0);
}
