/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:32:18 by byukim            #+#    #+#             */
/*   Updated: 2021/01/16 04:45:31 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_redir_in(t_process *proc)
{
	char	buf[1];
	int		p[2];
	int		fd;
	int		i;

	if (proc->in_idx)
	{
		pipe(p);
		i = -1;
		while (++i < proc->in_idx)
		{
			fd = open(proc->file_in[i], O_RDONLY);
			while (read(fd, buf, 1) > 0)
				write(p[1], buf, 1);
			close(fd);
		}
		dup2(p[0], 0);
		close(p[1]);
	}
}

void	pipe_redir_out(t_process *proc)
{
	int		fd;

	if (proc->out_idx)
	{
		if (proc->is_append[proc->out_idx - 1])
			fd = open(proc->file_out[proc->out_idx - 1],
					O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(proc->file_out[proc->out_idx - 1],
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd, 1);
	}
}

void	exec_pipe_else(t_process *proc)
{
	char	**argv;

	argv = process_argv(proc);
	pipe_redir_in(proc);
	pipe_redir_out(proc);
	ft_execvp(proc->argv[0], argv);
	ft_eprintf("%s: %s: command not found\n", SHELL_NAME, proc->argv[0]);
	free_2d_array(argv);
	exit(127);
}

void	exec_pipe(t_process *proc)
{
	if (!ft_strcmp(proc->argv[0], "cd"))
		wrapper_cd(proc);
	else if (!ft_strcmp(proc->argv[0], "exit"))
		ft_exit(g_laststat);
	else if (!ft_strcmp(proc->argv[0], "env"))
		wrapper_env();
	else if (!ft_strcmp(proc->argv[0], "export"))
		wrapper_export(proc);
	else if (!ft_strcmp(proc->argv[0], "unset"))
		wrapper_unset(proc);
	else if (!ft_strcmp(proc->argv[0], "pwd"))
		wrapper_pwd(proc);
	else if (!ft_strcmp(proc->argv[0], "echo"))
		wrapper_echo_pipe(proc);
	else
		exec_pipe_else(proc);
	exit(g_laststat);
}
