/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:41:42 by sehan             #+#    #+#             */
/*   Updated: 2021/05/13 17:21:05 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_mini	g_mini;

int	main(int argc, char *argv[], char *envp[])
{
	int i;

	argv = 0;
	argc = 0;
	i = -1;
	g_mini.pid = 0;
	tcgetattr(STDIN_FILENO, &g_mini.term);
	mini_init(&g_mini, envp);
	signal(SIGINT, (void *)sig);
	signal(SIGQUIT, sig);
	while (read(0, g_mini.str, 4) > 0)
	{
		g_mini.c = ft_stoi(g_mini.str);
		if (g_mini.c == ARROW_UP || g_mini.c == ARROW_DOWN)
			//arrow(&g_mini.lst_temp, g_mini.c);
			arrow(&g_mini.history, g_mini.c);
		else if (g_mini.c == 10)
			enter(&g_mini, envp);
		else if (g_mini.c == DELETE)
		{
			delete_end(0);
			if (ft_strlen(g_mini.history->content))
				g_mini.history->content[ft_strlen(g_mini.history->content) - 1] = 0;
		}
		else if (g_mini.c == CTRL_D)
			control_d(&g_mini);
		else
		{
			if (g_mini.c != 9 && g_mini.c >= 0 && g_mini.c <= 127)
			{
//				g_mini.temp = g_mini.lst_temp->content;
//				g_mini.lst_temp->content = ft_strjoin(g_mini.lst_temp->content, g_mini.str);
				g_mini.temp = g_mini.history->content;
				g_mini.history->content = ft_strjoin(g_mini.history->content, g_mini.str);
				free(g_mini.temp);
				write(1, g_mini.str, 1);
			}
		}
		ft_memset(g_mini.str, 0, 5);
	}
	return (0);
}
