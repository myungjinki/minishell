/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:42:40 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:46:05 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	space_helper(t_list *lst, char c)
{
	t_token	*token;

	while (c == ' ' && lst->next)
	{
		token = lst->next->content;
		if (token->name == ' ')
			lst_next_free(lst);
		else
			break ;
	}
}

int		space_token_compress(t_list *lst_begin)
{
	t_token	*token;
	t_list	*lst;
	t_list	*tmp;
	char	c;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		c = token->name;
		if (token->name == '\"' && (tmp = dquotes_token_find(lst)))
		{
			lst = tmp->next;
			continue ;
		}
		if (token->name == '\'' && (tmp = token_find(lst, '\'')))
		{
			lst = tmp->next;
			continue ;
		}
		space_helper(lst, c);
		lst = lst->next;
	}
	return (0);
}
