/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:20:22 by byukim            #+#    #+#             */
/*   Updated: 2021/01/15 21:30:57 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_redir_in(t_process *proc)
{
	int		i;
	int		fd;
	char	buf[1];
	int		p[2];

	if (proc->in_idx)
	{
		pipe(p);
		i = -1;
		while (++i)
		{
			fd = open(proc->file_in[i], O_RDONLY);
			while (read(fd, buf, 1) > 0)
				write(p[1], buf, 1);
			close(fd);
		}
		close(p[1]);
		dup2(p[0], 0);
	}
}

void	process_redir_out(t_process *proc)
{
	int		i;
	int		fd;

	i = -1;
	while (++i < proc->out_idx)
	{
		if (proc->is_append[i])
			fd = open(proc->file_out[i], O_WRONLY | O_CREAT | O_APPEND, 0644);
		else
			fd = open(proc->file_out[i], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(fd, 1);
	}
}
