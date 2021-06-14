/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:20:24 by mki               #+#    #+#             */
/*   Updated: 2021/06/09 13:00:41 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int is_rr(t_list *lst_begin)
{
	t_token	*token;
	t_list	*lst_next;
	t_token *token_next;

	token = lst_begin->content;
	lst_next = lst_begin->next;
	if (lst_next != NULL)
	{
		token_next = lst_next->content;
		if (token->name == '>' && token_next->name == '>')
			return (1);
	}
	return (0);
}

t_list *rr_redirection(t_list *lst_begin)
{
	lst_begin = 0;
	return (0);
}

t_list *r_redirection(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;
	
	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (token->name == ' ')
			lst = lst->next;
		token = lst->content;
		if (token->name == 's')
		{
			printf("%s\n", token->value);
			open(token->value, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRGRP | S_IROTH);
			lst_token_free(lst_begin, lst);
		}
		lst = lst->next;
	}
	return (0);
}

t_list *l_redirection(t_list *lst_begin)
{
	lst_begin = 0;
	return (0);
}

int	parser_redirection(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (is_rr(lst))
			lst = rr_redirection(lst);
		else if (token->name == '>')
			lst = r_redirection(lst);
		else if (token->name == '<')	
			lst = l_redirection(lst);
		lst = lst->next;
	}
	return (0);
}
