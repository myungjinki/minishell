/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/03 20:44:20 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*tmp(t_list **word, t_list *token)
{

}

void	check_token_name(t_list **lst_word, t_token *token)
{
	if (token->name = 's')
		ft_lstadd_back(lst_word, ft_lstnew(token->value));
	else if (token->name = ' ')
		;
	else if (token->name = '|')
		;
	else if (token->name = ';')
		;
	else if (token->name = '\"')
		;
	else if (token->name = '\'')
		;
}

t_word	*word_new(char *str)
{
	t_word	*ret;

	ret = (t_word *)malloc(sizeof(t_word));
	ret->argv[0] = str;
	ret->fd_in = NULL;
	ret->fd_out = NULL;
	return (ret);
}

t_list	*parser(t_list *lst_token)
{
	t_list	*lst_word;
	t_token	*token;

	lst_word = lst_token;
	while (lst_token)
	{
		token = lst_token->content;
		check_token_name(&lst_word, token);
		lst_token = lst_token->next;
	}
	return (lst_word);
}
