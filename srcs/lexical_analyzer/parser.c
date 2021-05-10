/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/10 21:44:49 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

// t_list	*syntax_pipe_semi(t_list *lst, int token_name)
// {
// 	return (lst);
// }

// t_list *syntax_redirection(t_list *lst, int token_name)
// {
// 	return (lst);
// }

// t_list	*syntax(t_list **lst, t_token *token)
// {
// 	if (token->name == '\'')
// 		*lst = syntax_quotes(*lst, token->name);
// 	else if (token->name == '\\')
// 		*lst = syntax_quotes(*lst, token->name);
// 	else if (token->name == ';' || token->name == '|')
// 		*lst = syntax_pipe_semi(*lst, token->name);
// 	else if (token->name == '>' || token->name == '<')
// 		*lst = syntax_redirection(*lst, token->name);
// 	else
// 		*lst = (*lst)->next;
// 	return (*lst);
// }

t_list	*parser_backquotes(t_list *lst_begin)
{
	t_list	*lst;

	lst = lst_begin;

	return (lst_begin);
}

t_list	*parser(t_list *lst_begin)
{
	if (parser_quotes(lst_begin) == NULL)
		return (NULL);
	if (parser_backquotes(lst_begin) == NULL)
		return (NULL);
	return (lst_begin);
}
