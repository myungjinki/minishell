/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_backslash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 12:50:48 by mki               #+#    #+#             */
/*   Updated: 2021/05/21 13:34:24 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	syntax_backslash(t_list *lst_begin)
{
	t_list	*lst;

	lst = lst_begin;
	while (lst)
	{
		if (lst_begin->next == NULL)
			return (syntax_error(BACKSLASH_MULTI));
		lst = lst->next;
	}
	return (0);
}
