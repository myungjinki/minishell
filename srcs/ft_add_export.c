/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:59:01 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 22:31:36 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		export_check(char **temp, int i, int *j)
{
	*j = 0;
	if ((temp[i][0] < 'A' || (temp[i][0] > 'Z' && temp[i][0] < 'a')
			|| temp[i][0] > 'z') && temp[i][0] != '_')
	{
		ft_putstr_fd("minishell: export: '", 2);
		ft_putstr_fd(temp[i], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
	}
	else
	{
		while (temp[i][++(*j)] != '=' && temp[i][*j])
		{
			if ((temp[i][*j] < '0' || (temp[i][*j] > '9' && temp[i][*j] < 'A')
					|| (temp[i][*j] > 'Z' && temp[i][*j] < 'a')
					|| temp[i][*j] > 'z') && temp[i][*j] != '_')
			{
				ft_putstr_fd("minishell: export: '", 2);
				ft_putstr_fd(temp[i], 2);
				ft_putstr_fd("': not a valid identifier\n", 2);
				break ;
			}
		}
	}
}

void		ft_add_export(t_mini *mini, char **temp)
{
	int i;
	int j;

	i = 1;
	while (temp[i])
	{
		export_check(temp, i, &j);
		if (!temp[i][j] || temp[i][j] == '=')
			ft_envp_lstadd(&mini->env, temp[i]);
		i++;
	}
}
