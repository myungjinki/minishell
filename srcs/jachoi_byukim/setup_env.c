/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 22:00:29 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:07:46 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern t_env *g_env;

void	add_env(t_env *env)
{
	t_env *last;

	last = g_env;
	if (!last)
		g_env = env;
	else
	{
		while (last->next)
			last = last->next;
		last->next = env;
		last = last->next;
	}
}

void	setup_env(char **envp)
{
	t_env	*iter;
	int		eq;

	iter = g_env;
	while (*envp)
	{
		iter = ft_calloc(1, sizeof(t_env));
		eq = ft_strchr(*envp, '=') - *envp;
		iter->key = ft_substr(*envp, 0, eq);
		iter->value = ft_substr(*envp, eq + 1, ft_strlen(*envp) - eq - 1);
		add_env(iter);
		envp++;
	}
	setup_path();
}
