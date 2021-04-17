/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 16:59:01 by sehan             #+#    #+#             */
/*   Updated: 2021/04/17 17:28:38 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	find_equal(char *str)
{
	int i;

	result = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_add_export(t_mini *mini, char *temp)
{
	char	**split;
	char	**split_equal;
	int		i;
	int		find;
	
	split = ft_split(temp);
	i = 1;
	while (split[i])
	{
		find = find_equal(split[i]);
		if (find)
		{
			
		}
		i++;
	}
}
