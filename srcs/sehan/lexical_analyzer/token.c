/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:37:22 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:37:26 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

t_list	*token_find(t_list *lst, char c)
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

void	token_free(t_list *lst)
{
	free(((t_token *)lst->content)->value);
	((t_token *)lst->content)->value = NULL;
	free(lst->content);
	lst->content = NULL;
	free(lst);
	lst = NULL;
}

t_list	*lst_next_free(t_list *lst)
{
	t_list	*ret;
	t_list	*lst_next;

	ret = NULL;
	lst_next = lst->next;
	if (lst_next)
	{
		ret = lst_next->next;
		token_free(lst_next);
		lst->next = ret;
	}
	return (ret);
}

void	lst_token_free(t_list *start)
{
	t_list	*lst;
	t_token *token;

	while (start)
	{
		lst = start;
		start = start->next;
		token = lst->content;
		free(token->value);
		free(token);
		free(lst);
	}
}
