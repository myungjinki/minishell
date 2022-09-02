/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byukim <byukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 04:40:16 by byukim            #+#    #+#             */
/*   Updated: 2021/01/16 05:01:30 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wrapper_echo(t_process *proc)
{
	wrapper_execvp(proc);
}

void	wrapper_echo_pipe(t_process *proc)
{
	exec_pipe_else(proc);
}
