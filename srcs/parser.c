/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/03 20:19:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*tmp(t_list **word, t_list *token)
{

}

t_list	*parser(t_list *lst_token)
{
	t_list	*lst_word;

	lst_word = lst_token;
	while (lst_token)
	{
		
		// printf("%s\n", ((t_token *)lst_token->content)->value);
		lst_token = lst_token->next;
	}
	return (lst_word);
}
