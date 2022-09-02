/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 21:50:47 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/16 04:39:27 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	waitpids(int k)
{
	int status;

	while (k >= 0)
	{
		waitpid(g_pids[k], &status, 0);
		g_laststat = WEXITSTATUS(stat);
		k--;
	}
}

void	exec_normal(t_process *proc)
{
	if (!ft_strcmp(proc->argv[0], "cd"))
		wrapper_cd(proc);
	else if (!ft_strcmp(proc->argv[0], "exit"))
		wrapper_exit(proc);
	else if (!ft_strcmp(proc->argv[0], "env"))
		wrapper_env();
	else if (!ft_strcmp(proc->argv[0], "export"))
		wrapper_export(proc);
	else if (!ft_strcmp(proc->argv[0], "unset"))
		wrapper_unset(proc);
	else if (!ft_strcmp(proc->argv[0], "pwd"))
		wrapper_pwd(proc);
	else if (!ft_strcmp(proc->argv[0], "echo"))
		wrapper_echo(proc);
	else
		wrapper_execvp(proc);
}

void	stdio_redir(int i, int j, int k)
{
	if (k != i)
	{
		if (g_procmgr[k - 1]->out_idx)
			dup2(open(g_procmgr[k - 1]->
				file_out[g_procmgr[k - 1]->out_idx - 1], O_RDONLY), 0);
		else
			dup2(g_pipe[k - i][0], 0);
	}
	if (k != j)
		dup2(g_pipe[k - i + 1][1], 1);
	exec_pipe(g_procmgr[k]);
}

void	exec_pipeline(int i, int j)
{
	int k;

	k = -1;
	while (++k <= j - i)
		pipe(g_pipe[k]);
	k = i - 1;
	while (++k <= j)
	{
		if (!(g_pids[k - i] = fork()))
			stdio_redir(i, j, k);
		if (k != i)
			close(g_pipe[k - i][0]);
		if (k != j)
			close(g_pipe[k - i + 1][1]);
		if (g_procmgr[k]->out_idx)
			waitpid(k - i, 0, 0);
	}
	waitpids(j - i);
}

void	exec_cmdline(void)
{
	int		i;
	int		j;
	int		stat;

	stat = 0;
	i = -1;
	while (g_procmgr[++i])
	{
		if (g_procmgr[i]->is_pipe)
		{
			j = i + 1;
			while (g_procmgr[j] && g_procmgr[j]->prev_pipe)
				j++;
			exec_pipeline(i, j - 1);
			i = j - 1;
		}
		else
			exec_normal(g_procmgr[i]);
	}
}
