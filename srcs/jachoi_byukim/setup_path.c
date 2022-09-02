/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:53:53 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/02 17:28:27 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_path(char *data)
{
	t_list *last;

	last = g_path;
	if (!last)
	{
		last = ft_calloc(1, sizeof(t_list));
		g_path = last;
	}
	else
	{
		while (last->next)
			last = last->next;
		last->next = ft_calloc(1, sizeof(t_list));
		last = last->next;
	}
	last->content = ft_substr(data, 0, ft_strlen(data));
}

void	setup_path(void)
{
	t_env *const	path = get_env("PATH");
	char			**tmp;
	char			**iter;

	tmp = NULL;
	if (path)
	{
		tmp = ft_split(path->value, ':');
		iter = tmp;
		if (g_path)
		{
			ft_lstclear(&g_path, free);
			g_path = NULL;
		}
		while (iter && *iter)
			add_path(*iter++);
		free_2d_array(tmp);
	}
}
