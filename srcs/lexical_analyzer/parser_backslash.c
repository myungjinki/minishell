/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:25:33 by mki               #+#    #+#             */
/*   Updated: 2021/05/13 15:38:27 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

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
	{
		token[0]->name = 's';
		free(token[0]->value);
		token[0]->value = token[1]->value;
		lst->next = lst_next->next;
		free(lst_next->content);
		free(lst_next);
	}
	return (0);
}

int	parser_backslash(t_list *lst_begin, int flag)
{
	t_list	*lst;
	t_token *token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == '\\' && backslash_special(lst))
			return (syntax_error(ERROR_BACKSLASH));
		lst = lst->next;
	}
	return (0);
}
