/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/05 16:11:23 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list 	*syntax_quotes(t_list *lst, int token_name)
{
	return (lst);
}

t_list	*syntax_pipe_semi(t_list *lst, int token_name)
{
	return (lst);
}

t_list *syntax_redirection(t_list *lst, int token_name)
{
	return (lst);
}

t_list	*syntax(t_list **lst, t_token *token)
{
	if (token->name == '\"' || token->name == '\'')
		syntax_quotes(*lst, token->name);
	else if (token->name == ';' || token->name == '|')
		syntax_pipe_semi(*lst, token->name);
	else if (token->name == '>' || token->name == '<')
		syntax_redirection(*lst, token->name);
	else
		*lst = (*lst)->next;
	return (*lst);
}

t_list	*parser(t_list *lst_token)
{
	t_list	*lst_begin;
	t_token	*token;

	lst_begin = lst_token;
	while (lst_token)
	{
		token = lst_token->content;
		lst_token = syntax(&lst_begin, token);
	}
	return (lst_begin);
}
