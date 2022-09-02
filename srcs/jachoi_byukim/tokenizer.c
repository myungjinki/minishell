/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jachoi <jachoi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 18:46:15 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/16 05:02:11 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	g_stat;
int		g_type;
char	*g_val;

void	append_token(char *value)
{
	t_token *iter;
	t_token *tok;

	if (!value)
		return ;
	if (!g_token)
	{
		g_token = ft_calloc(1, sizeof(t_token));
		g_token->data = value;
		g_token->type = g_type;
		g_type = TOKEN_NORMAL;
		return ;
	}
	iter = g_token;
	while (iter->next)
		iter = iter->next;
	tok = ft_calloc(1, sizeof(t_token));
	tok->data = value;
	tok->type = g_type;
	g_type = TOKEN_NORMAL;
	iter->next = tok;
}

char	*end_tokenizer(void)
{
	t_token	*iter;

	iter = g_token;
	while (iter)
	{
		if (!ft_strcmp(iter->data, "~"))
			iter->data = get_env_value("HOME");
		assign_type(iter);
		iter = iter->next;
	}
	g_val = 0;
	return (check_parse_error());
}

void	case_quotes(char *cmd)
{
	if (g_stat == *cmd)
		g_stat = 0;
	else
	{
		if (g_stat == '\'')
			g_val = append_char(g_val, *cmd);
		else if (*cmd == '\\' && cmd[1] == '\\')
			return ;
		else
			g_val = append_char(g_val, *cmd);
		if (!g_token)
			return ;
	}
}

void	case_special(char **pcmd)
{
	char	*cmd;

	cmd = *pcmd;
	append_token(g_val);
	g_val = 0;
	if (!ft_strchr("<|;", *cmd))
	{
		if (cmd[0] == cmd[1])
		{
			append_token(ft_strdup(">>"));
			(*pcmd)++;
			return ;
		}
	}
	append_token(append_char(0, *cmd));
}

char	*tokenizer(char *cmd)
{
	if (!*cmd)
	{
		if (ft_slen(g_val))
			append_token(g_val);
		return (end_tokenizer());
	}
	if (g_stat == '\'' || g_stat == '\"')
		case_quotes(cmd);
	else if (g_stat == '\\')
		return (case_backslash(cmd));
	else
	{
		if (ft_strchr("<>|;", *cmd))
			case_special(&cmd);
		else if (ft_strchr("\'\"\\", *cmd))
			g_stat = *cmd;
		else if (ft_isspace(*cmd))
		{
			append_token(g_val);
			g_val = 0;
		}
		else
			g_val = append_char(g_val, *cmd);
	}
	return (tokenizer(cmd + 1));
}
