/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:52:42 by mki               #+#    #+#             */
/*   Updated: 2021/05/13 18:52:55 by mki              ###   ########.fr       */
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
