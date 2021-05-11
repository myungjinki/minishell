/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:39:56 by mki               #+#    #+#             */
/*   Updated: 2021/05/11 11:33:51 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

t_list	*make_string(t_list *start, t_list *end)
{
	t_list	*lst;
	t_token *token;
	char	*str_ret;
	char	*tmp;

	str_ret = (char *)ft_calloc(1, sizeof(char));
	lst = start->next;
	while (lst != end)
	{
		token = lst->content;
		tmp = ft_strjoin(str_ret, token->value);
		free(str_ret);
		str_ret = tmp;
		lst = lst->next;
	}
	token = start->content;
	token->name = 's';
	token->value = str_ret;
	start->next = end->next;
	return (end);
}

t_list	*find_quotes(t_list *lst, char c)
{
	t_token	*token;

	lst = lst->next;
	while (lst)
	{
		token = lst->content;
		if (token->name == c)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

int		parser_quotes(t_list *lst_begin)
{
	t_list	*lst;
	t_list	*end;
	t_token *token;

	lst = lst_begin;
	end = NULL;
	while (lst)
	{
		token = lst->content;
		if (token->name == '\'')
		{
			end = find_quotes(lst, '\'');
			if (end)
				lst = make_string(lst, end);
			else
				return (1);
		}
		lst = lst->next;
	}
	return (0);
}
