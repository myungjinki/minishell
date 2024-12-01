/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:39:56 by mki               #+#    #+#             */
/*   Updated: 2021/05/21 13:38:52 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int		parser_quotes(t_list *lst_begin)
{
	t_list	*lst;
	t_list	*end;

	lst = lst_begin;
	end = token_find(lst, '\'');
	if (end)
		lst = make_string(lst, end);
	else
		return (syntax_error(QUOTES_MULTI));
	return (0);
}
