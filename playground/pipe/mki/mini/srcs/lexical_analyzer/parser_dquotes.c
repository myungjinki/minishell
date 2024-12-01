/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:19:30 by mki               #+#    #+#             */
/*   Updated: 2021/05/21 13:30:12 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	parser_dquotes(t_list *lst_begin, t_envp_list *lst_envp, int status)
{
	t_list	*lst;
	t_list	*end;
	t_token	*token;

	lst = lst_begin;
	end = token_find(lst, '\"');
	while (lst != end)
	{
		token = lst->content;
		if (token->name == '\\' && parser_backslash(lst, 1))
			return (syntax_error(BACKSLASH_MULTI));
		else if (token->name == '$' && parser_env(lst, lst_envp, status))
			return (syntax_error(DQUOTES_MULTI));
		lst = lst->next;
	}
	if (end)
		make_string(lst_begin, end);
	else
		return (syntax_error(DQUOTES_MULTI));
	return (0);
}
