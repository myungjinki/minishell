/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:26:28 by sehan             #+#    #+#             */
/*   Updated: 2021/05/13 18:41:59 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_mini mini, char *str)
{
	if (ft_strcmp(str, "env") == 0)
	{
		if (!ft_find_env(mini.env, "PATH"))
		{
			printf("env: No such file or directory\n");
			g_mini.status = 127;
			return ;
		}
		while (mini.env)
		{
			if (mini.env->value && ft_strcmp(mini.env->value, ""))
				printf("%s=%s\n", mini.env->key, mini.env->value);
			mini.env = mini.env->next;
		}
	}
	else
		while (mini.env)
		{
			printf("declare - x %s", mini.env->key);
			if (mini.env->value)
				printf("=\"%s\"", mini.env->value);
			printf("\n");
			mini.env = mini.env->next;
		}
}
