/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:54:50 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:05:37 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d_exit(void)
{
	write(1, "\n", 1);
	ft_exit(g_laststat);
}

char	*readline(void)
{
	char	buf[1];
	char	*out;
	int		result;
	bool	ctrld;

	out = ft_calloc(1, sizeof(char));
	ctrld = true;
	while (ctrld)
	{
		ctrld = false;
		while ((result = read(0, buf, 1)) > 0)
		{
			if (*buf == '\n')
				break ;
			out = append_char(out, *buf);
		}
		if (!result)
		{
			if (!ft_strlen(out))
				ctrl_d_exit();
			ctrld = true;
		}
	}
	return (out);
}

void	hook(int signo)
{
	if (signo == SIGINT)
	{
		g_laststat = 130;
		write(1, "\b\b  \n", 5);
		prompt();
	}
	else if (signo == SIGTSTP || signo == SIGQUIT)
		write(1, "\b\b​​  \b\b", 12);
}

int		main(int argc, char **argv, char **envp)
{
	char *command;

	(void)argc;
	(void)argv;
	setup_env(envp);
	signal(SIGQUIT, hook);
	signal(SIGTSTP, hook);
	signal(SIGINT, hook);
	while (true)
	{
		prompt();
		command = readline();
		cmd(command);
		free(command);
	}
}
