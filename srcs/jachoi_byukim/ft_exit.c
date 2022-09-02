/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 21:38:02 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:07:54 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_exit(int exitcode)
{
	write(1, "exit\n", 5);
	exit(exitcode);
}

void	wrapper_exit(t_process *proc)
{
	if (!proc->is_pipe && !proc->idx)
		ft_exit(g_laststat);
	else if (!proc->is_pipe)
		ft_exit(ft_atoi(proc->argv[1]));
}
