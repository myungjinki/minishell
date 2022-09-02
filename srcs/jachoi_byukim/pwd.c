/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 13:46:08 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/16 00:44:33 by jachoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wrapper_pwd(t_process *proc)
{
	char result[MAX_FILENAME];

	if (proc->idx != 1)
	{
		ft_eprintf("pwd: too many arguments\n");
		g_laststat = 1;
		return ;
	}
	getcwd(result, MAX_FILENAME);
	ft_printf("%s\n", result);
}
