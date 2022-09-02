/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 17:03:26 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:08:02 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		total_env(void)
{
	t_env	*iter;
	int		i;

	iter = g_env;
	i = 0;
	while (iter)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}

t_env	*get_env(char *key)
{
	t_env *iter;

	iter = g_env;
	while (iter)
	{
		if (ft_strcmp(iter->key, key) == 0)
			return (iter);
		iter = iter->next;
	}
	return (NULL);
}

char	*get_env_value(char *key)
{
	t_env	*env;

	if (!(env = get_env(key)))
		return (ft_strdup(""));
	return (ft_strdup(env->value));
}

void	wrapper_env(void)
{
	t_env *iter;

	iter = g_env;
	while (iter)
	{
		ft_printf("%s=%s\n", iter->key, iter->value);
		iter = iter->next;
	}
}
