/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 10:26:33 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:06:01 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	wrapper_execvp(t_process *proc)
{
	char	**argv;
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		argv = process_argv(proc);
		process_redir_in(proc);
		process_redir_out(proc);
		ft_execvp(proc->argv[0], argv);
		ft_eprintf("%s: %s: command not found\n", SHELL_NAME, proc->argv[0]);
		free_2d_array(argv);
		exit(127);
	}
	waitpid(pid, &status, 0);
	g_laststat = WEXITSTATUS(status);
	return (pid);
}

void	add_process(t_process *proc)
{
	int last;

	last = 0;
	while (g_procmgr[last])
		last++;
	g_procmgr[last] = proc;
	if (last >= 1 && g_procmgr[last - 1]->is_pipe)
		proc->prev_pipe = true;
}

void	clear_procmgr(void)
{
	int idx;

	idx = 0;
	while (g_procmgr[idx])
	{
		free(g_procmgr[idx]);
		g_procmgr[idx++] = NULL;
	}
}

void	parse_and_exec(void)
{
	t_token		*iter;

	iter = g_token;
	while (iter)
	{
		add_process(process(iter));
		while (iter && iter->type < TOKEN_PIPE)
			iter = iter->next;
		if (iter)
			iter = iter->next;
	}
	exec_cmdline();
	clear_procmgr();
}
