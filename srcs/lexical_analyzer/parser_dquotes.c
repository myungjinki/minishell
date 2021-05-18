/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_dquotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:19:30 by mki               #+#    #+#             */
/*   Updated: 2021/05/18 16:13:35 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	parser_dquotes(t_list *lst_begin, t_envp_list *lst_envp, int status)
{
	lst_begin = 0;
	lst_envp = 0;
	status = 0;
	// t_list	*lst;

	// lst = lst_begin;
	// while (lst)
	// {
	// 	parser_backslash(lst, 1);
	// 	parser_env(lst, lst_envp, status);
	// 	lst = lst->next;
	// }
	return (0);
}
