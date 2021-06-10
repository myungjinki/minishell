/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:54:15 by mki               #+#    #+#             */
/*   Updated: 2021/06/10 12:47:31 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

t_word	*make_word(t_list *lst)
{
	
}

t_list	*make_word_list(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;
	t_word	*word;

	print_lst_token(lst_begin);
	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		word = make_word(lst_begin);
	}
	// lst_token_free(lst_begin, NULL);
	return (NULL);
}