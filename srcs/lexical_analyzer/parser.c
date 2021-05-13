/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/13 16:15:50 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	parser_if(t_list *lst, t_envp_list *lst_envp, char name)
{
	if (name == '\\')
		return (parser_backslash(lst, 0));
	else if (name == '\"')
		return (parser_dquotes(lst, lst_envp));
	else if (name == '$')
		return (parser_env(lst, lst_envp));
	else if (name == '|')
		return (parser_pipeline(lst));
	else if (name == '\'')
		return (parser_quotes(lst));
	else if (name == '>' || name == '<')
		return (parser_redirection(lst));
	else if (name == ';')
		return (parser_semicolon(lst));
	return (0);
}

int	parser(t_list *lst_begin, t_envp_list *lst_envp) 
{
	t_list	*lst;
	t_token *token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (parser_if(lst, lst_envp, token->name))
			return (1);
		lst = lst->next;
	}
	return (0);
}
