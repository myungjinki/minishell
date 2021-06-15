/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/06/15 12:53:13 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	syntax_check(t_list *lst_begin)
{
	if (syntax_redirection(lst_begin))
		return (1);
	return (0);
}

int	parser_if(t_list *lst, t_envp_list *lst_envp, char name, int status)
{
	if (name == '\\')
		return (parser_backslash(lst, 0));
	else if (name == '\"')
		return (parser_dquotes(lst, lst_envp, status));
	else if (name == '$')
		return (parser_env(lst, lst_envp, status));
	else if (name == '\'')
		return (parser_quotes(lst));
	return (0);
}

int	parser(t_list *lst_begin, t_envp_list *lst_envp, int status)
{
	t_list	*lst;
	t_token *token;

	if (syntax_check(lst_begin))
		return (1);
	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (parser_if(lst, lst_envp, token->name, status))
			return (1);
		lst = lst->next;
	}
	return (0);
}
