/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:34:45 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:34:48 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	isspecial_in_dquote(char c)
{
	if (c == '`' || c == '\\' || c == '\"' || c == '$')
		return (1);
	return (0);
}

int	parser_backslash(t_list *lst, int mode)
{
	t_token	*token[2];
	t_list	*lst_next;
	char	c;

	lst_next = lst->next;
	if (lst->next == NULL)
		return (syntax_error(BACKSLASH_MULTI));
	token[0] = lst->content;
	token[1] = lst_next->content;
	c = token[1]->name;
	if (mode == 1 && !isspecial_in_dquote(c))
		return (0);
	token[0]->name = 's';
	free(token[0]->value);
	token[0]->value = token[1]->value;
	lst->next = lst_next->next;
	free(lst_next->content);
	free(lst_next);
	return (0);
}
