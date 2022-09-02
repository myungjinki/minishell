/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byukim <byukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 15:26:23 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:06:16 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_process	*process(t_token *tok)
{
	t_process *const	proc = ft_calloc(1, sizeof(t_process));
	int					lasttype;

	lasttype = 0;
	while (tok)
	{
		if (tok->next && tok->next->type >= TOKEN_PIPE)
			proc->is_pipe = TOKEN_SEMICOLON - tok->next->type;
		if (lasttype == TOKEN_APPEND)
		{
			proc->is_append[proc->out_idx] = true;
			ft_strlcpy(proc->file_out[proc->out_idx++], tok->data, 1024);
		}
		else if (lasttype == TOKEN_OUT_REDIR)
			ft_strlcpy(proc->file_out[proc->out_idx++], tok->data, 1024);
		else if (lasttype == TOKEN_IN_REDIR)
			ft_strlcpy(proc->file_in[proc->in_idx++], tok->data, 1024);
		else if (tok->type == TOKEN_NORMAL)
			ft_strlcpy(proc->argv[proc->idx++], tok->data, 1024);
		else if (tok->type >= TOKEN_PIPE)
			break ;
		lasttype = tok->type;
		tok = tok->next;
	}
	return (proc);
}
