/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 19:58:42 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 21:00:01 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**env_to_arr2(void)
{
	char		**ret;
	int			idx;
	char		*tmp;
	t_env		*iter;

	ret = ft_calloc(total_env() + 3, sizeof(char*));
	iter = g_env;
	idx = 0;
	while (iter)
	{
		tmp = ft_calloc(ft_strlen(iter->key) + ft_strlen(iter->value) + 3, 1);
		ft_memcpy(tmp, iter->key, ft_strlen(iter->key));
		tmp[ft_strlen(iter->key)] = '=';
		tmp[ft_strlen(iter->key) + 1] = '\"';
		ft_memcpy(tmp + ft_strlen(iter->key) + 2,
			iter->value, ft_strlen(iter->value));
		tmp[ft_strlen(iter->key) + ft_strlen(iter->value) + 2] = '\"';
		ret[idx++] = tmp;
		iter = iter->next;
	}
	return (ret);
}

void	show_export(int i, int j)
{
	int		cnt;
	char	**arr;
	char	*tmp;

	arr = env_to_arr2();
	cnt = 0;
	while (arr[cnt])
		cnt++;
	while (++i < cnt)
	{
		j = -1;
		while (++j < cnt)
		{
			if (ft_strcmp(arr[i], arr[j]) < 0)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	i = -1;
	while (++i < cnt)
		ft_printf("declare -x %s\n", arr[i]);
	free_2d_array(arr);
}

void	when_found(t_env *iter, char *key, char *value)
{
	free(iter->value);
	free(key);
	iter->value = value;
}

void	set_env(char *key, char *value)
{
	t_env	*iter;
	t_env	*prev;
	bool	found;

	if (!valid_identifier(key))
		return (void)ft_eprintf("export: not an identifier: %s\n", key);
	found = false;
	iter = g_env;
	while (iter && !found)
	{
		if (!ft_strcmp(iter->key, key))
		{
			when_found(iter, key, value);
			found = true;
			break ;
		}
		prev = iter;
		iter = iter->next;
	}
	if (!found)
	{
		prev->next = ft_calloc(1, sizeof(t_env));
		prev->next->key = key;
		prev->next->value = value;
	}
}

void	wrapper_export(t_process *proc)
{
	char	*str;
	char	*t;
	int		i;

	if (proc->idx == 1)
		show_export(-1, -1);
	else
	{
		i = 0;
		while (++i < proc->idx)
		{
			str = proc->argv[i];
			if (!(t = ft_strchr(str, '=')))
			{
				set_env(ft_substr(str, 0, ft_strlen(str)), ft_strdup(""));
			}
			else
			{
				set_env(ft_substr(str, 0, t - str),
				ft_substr(t + 1, 0, ft_strlen(t + 1)));
			}
		}
	}
}
