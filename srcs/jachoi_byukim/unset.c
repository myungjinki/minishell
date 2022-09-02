/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:19:56 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/11 04:49:25 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char *key)
{
	t_env *prev;
	t_env *next;
	t_env *iter;

	prev = NULL;
	next = NULL;
	iter = g_env;
	while (iter)
	{
		if (!ft_strcmp(iter->key, key))
		{
			prev->next = iter->next;
			free(iter->key);
			free(iter->value);
			free(iter);
			iter = prev;
		}
		else
			prev = iter;
		iter = iter->next;
	}
}

void	wrapper_unset(t_process *proc)
{
	int i;

	if (proc->idx > 1)
	{
		i = 0;
		while (++i < proc->idx)
		{
			if (valid_identifier(proc->argv[i]))
				unset(proc->argv[i]);
			else
			{
				ft_eprintf("%s: unset: `%s': not a valid identifier\n",
					SHELL_NAME, proc->argv[i]);
				g_laststat = 1;
			}
		}
	}
}
