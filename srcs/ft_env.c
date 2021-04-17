/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:26:28 by sehan             #+#    #+#             */
/*   Updated: 2021/04/17 16:55:58 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(t_mini mini, char *str)
{
	if (ft_strcmp(str, "env") == 0)
		while (mini.env)
		{
			printf("%s=%s\n", mini.env->key, mini.env->value);
			mini.env = mini.env->next;
		}
	else
	{
		while (mini.env)
		{
			if (ft_strcmp(mini.env->value, ""))
				printf("%s=\"%s\"\n", mini.env->key, mini.env->value);
			mini.env = mini.env->next;
		}
	}
}
