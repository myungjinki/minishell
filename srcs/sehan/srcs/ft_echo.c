/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:45:38 by sehan             #+#    #+#             */
/*   Updated: 2021/06/15 19:01:40 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_option(char **str, int *i)
{
	int j;
	int result;

	j = 1;
	result = 0;
	while (str[*i])
	{
		if (!ft_strncmp(str[*i], "-n", 2))
			while (str[*i][j] == 'n')
				j++;
		else
			break ;
		if (!str[*i][j])
		{
			j = 1;
			(*i)++;
			result = 1;
		}
		else
			break ;
	}
	return (result);
}

void		ft_echo(char **str)
{
	int i;
	int flag;

	i = 1;
	flag = is_option(str, &i);
	while (str[i])
	{
		ft_putstr_fd(str[i], 1);
		if (str[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (!flag)
		write(1, "\n", 1);
}
