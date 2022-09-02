/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 14:56:56 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:05:13 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_arr(void)
{
	char		**ret;
	int			idx;
	char		*tmp;
	t_env		*iter;

	ret = ft_calloc(total_env() + 1, sizeof(char*));
	iter = g_env;
	idx = 0;
	while (iter)
	{
		tmp = ft_calloc(ft_strlen(iter->key) + ft_strlen(iter->value) + 2, 1);
		ft_memcpy(tmp, iter->key, ft_strlen(iter->key));
		tmp[ft_strlen(iter->key)] = '=';
		ft_memcpy(tmp + ft_strlen(iter->key) + 1,
			iter->value, ft_strlen(iter->value));
		ret[idx++] = tmp;
		iter = iter->next;
	}
	return (ret);
}

void	free_2d_array(char **arr)
{
	char *const *base = arr;

	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free((void*)base);
}

char	**process_argv(t_process *proc)
{
	char	**ret;
	int		idx;
	int		len;

	ret = ft_calloc(proc->idx + 1, sizeof(char*));
	idx = 0;
	while (idx < proc->idx)
	{
		len = ft_strlen(proc->argv[idx]);
		ret[idx] = ft_calloc(len + 1, sizeof(char));
		ft_strlcpy(ret[idx], proc->argv[idx], len + 1);
		idx++;
	}
	return (ret);
}
