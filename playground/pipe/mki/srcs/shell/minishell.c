/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:23:58 by mki               #+#    #+#             */
/*   Updated: 2021/04/22 13:48:10 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    minishell(char **envp[])
{
	int i;

	i = -1;
	g_mini.pid = 0;
	tcgetattr(STDIN_FILENO, &g_mini.term);
	mini_init(&g_mini, *envp);
	signal(SIGINT, (void *)sig);
	signal(SIGQUIT, sig);
	while (read(0, g_mini.str, 4) > 0)
	{
		g_mini.c = ft_stoi(g_mini.str);
		if (g_mini.c == ARROW_UP || g_mini.c == ARROW_DOWN)
			arrow(&g_mini.lst_temp, g_mini.c);
		else if (g_mini.c == 10)
			enter(&g_mini, *envp);
		else if (g_mini.c == DELETE)
		{
			delete_end(0);
			if (ft_strlen(g_mini.lst_temp->content))
				g_mini.lst_temp->content[ft_strlen(g_mini.lst_temp->content) - 1] = 0;
		}
		else if (g_mini.c == CTRL_D)
			control_d(&g_mini);
		else
		{
			g_mini.temp = g_mini.lst_temp->content;
			g_mini.lst_temp->content = ft_strjoin(g_mini.lst_temp->content, g_mini.str);
			free(g_mini.temp);
			write(1, g_mini.str, 1);
		}
		ft_memset(g_mini.str, 0, 5);
	}
}