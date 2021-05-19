/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:13:06 by sehan             #+#    #+#             */
/*   Updated: 2021/05/17 16:41:44 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lst_free(t_list *lst)
{
	t_list *temp;
	t_list *free_temp;

	while (lst)
	{
		temp = (t_list *)lst->content;
		while (temp)
		{
			free_temp = temp;
			temp = free_temp->next;
			free_split(free_temp->content);
			free(free_temp);
		}
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}