/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/11 12:08:29 by mki              ###   ########.fr       */
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

int	backslash_special(t_list *lst)
{
	t_token	*token[2];
	t_list	*lst_next;
	char	c;

	if (lst->next == NULL)
		return (1);
	lst_next = lst->next;
	token[0] = lst->content;
	token[1] = lst_next->content;
	c = token[1]->name;
	if (c == '`' || c == '\\' || c == '\"' || c == '$')
		;
	lst->next = lst_next->next;
	ft_lstdelone(lst_next, free);
	return (0);
}

int	*parser_backslash(t_list *lst_begin)
{
	t_list	*lst;
	t_token *token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == '\\' && backslash_special(lst))
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	parser(t_list *lst_begin)
{
	if (parser_quotes(lst_begin))
		return (syntax_error(ERROR_QUOTE));
	if (parser_backslash(lst_begin) == NULL)
		return (syntax_error(ERROR_BACKSLASH));
	return (0);
}
