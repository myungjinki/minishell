/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:12:40 by mki               #+#    #+#             */
/*   Updated: 2021/05/17 13:18:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	token_free(t_list *lst)
{
	free(((t_token *)lst->content)->value);
	free(lst->content);
	free(lst);
}

void	lst_token_free(t_list *lst)
{
	t_list	*tmp;
	while (lst)
	{
		tmp = lst->next;
		token_free(lst);
		lst = tmp;
	}
}