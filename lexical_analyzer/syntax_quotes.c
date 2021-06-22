/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:36:55 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:36:58 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	syntax_dquotes(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == '\'')
			lst = token_find(lst, '\'');
		if (!lst)
			return (syntax_error(QUOTES_MULTI));
		lst = lst->next;
	}
	return (0);
}

int	syntax_quotes(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == '\'')
			lst = token_find(lst, '\'');
		if (!lst)
			return (syntax_error(QUOTES_MULTI));
		lst = lst->next;
	}
	return (0);
}
