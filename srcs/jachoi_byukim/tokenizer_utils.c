/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 21:49:07 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/15 02:07:28 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	g_stat;
extern int	g_type;
extern char	*g_val;

void	assign_type(t_token *iter)
{
	if (!ft_strcmp(">>", iter->data))
		iter->type = TOKEN_APPEND;
	if (!ft_strcmp(">", iter->data))
		iter->type = TOKEN_OUT_REDIR;
	if (!ft_strcmp("<", iter->data))
		iter->type = TOKEN_IN_REDIR;
	if (!ft_strcmp("|", iter->data))
		iter->type = TOKEN_PIPE;
	if (!ft_strcmp(";", iter->data))
		iter->type = TOKEN_SEMICOLON;
}

char	*type_definer(t_token *next)
{
	if (!next)
		return ("\\n");
	if (next->type == TOKEN_APPEND)
		return (">>");
	if (next->type == TOKEN_OUT_REDIR)
		return (">");
	if (next->type == TOKEN_IN_REDIR)
		return ("<");
	if (next->type == TOKEN_SEMICOLON)
		return (";");
	return (0);
}

char	*check_parse_error(void)
{
	t_token *iter;
	char	*s;

	iter = g_token;
	if (!iter)
		return ("permission denied");
	if (iter->type == TOKEN_PIPE)
		return ("|");
	if (iter->type == TOKEN_SEMICOLON)
		return (";");
	while (iter)
	{
		if (iter->type != 0 && iter->next && iter->next->type == TOKEN_PIPE)
			return ("|");
		if (1 <= iter->type && iter->type <= 3)
		{
			if ((s = type_definer(iter->next)))
				return (s);
		}
		iter = iter->next;
	}
	return (0);
}

char	*case_backslash(char *cmd)
{
	g_val = append_char(g_val, *cmd);
	g_stat = 0;
	return (tokenizer(cmd + 1));
}
