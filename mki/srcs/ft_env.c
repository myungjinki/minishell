/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:26:28 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 17:17:22 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_env(t_mini mini, char *str)
{
	if (ft_strcmp(str, "env") == 0)
		while (mini.env)
		{
			if (mini.env->value && ft_strcmp(mini.env->value, ""))
				printf("%s=%s\n", mini.env->key, mini.env->value);
			mini.env = mini.env->next;
		}
	else
	{
		while (mini.env)
		{
			printf("declare - x %s", mini.env->key);
			if (mini.env->value)
				printf("=\"%s\"", mini.env->value);
			printf("\n");
			mini.env = mini.env->next;
		}
	}
}
