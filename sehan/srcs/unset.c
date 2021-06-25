/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:25:11 by sehan             #+#    #+#             */
/*   Updated: 2021/06/21 21:30:26 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	unset_check(char **temp, int i, int *j)
{
	*j = 0;
	if ((temp[i][0] < 'A' || (temp[i][0] > 'Z' && temp[i][0] < 'a')
			|| temp[i][0] > 'z') && temp[i][0] != '_')
	{
		ft_putstr_fd("minishell: unset: '", 2);
		ft_putstr_fd(temp[i], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		return (1);
	}
	else
	{
		while (temp[i][++(*j)] != '=' && temp[i][*j])
		{
			if ((temp[i][*j] < '0' || (temp[i][*j] > '9' && temp[i][*j] < 'A')
					|| (temp[i][*j] > 'Z' && temp[i][*j] < 'a')
					|| temp[i][*j] > 'z') && temp[i][*j] != '_')
			{
				ft_putstr_fd("minishell: unset: '", 2);
				ft_putstr_fd(temp[i], 2);
				ft_putstr_fd("': not a valid identifier\n", 2);
				return (1);
			}
		}
	}
	return (0);
}

void		unset(t_mini *mini, t_envp_list **lst, char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		mini->status = unset_check(str, i, &j);
		ft_envp_lstdelone(lst, str[i]);
		i++;
	}
}
