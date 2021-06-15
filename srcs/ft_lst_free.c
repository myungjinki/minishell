/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:13:06 by sehan             #+#    #+#             */
/*   Updated: 2021/06/14 18:19:27 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lst_free(t_list *lst)
{
	t_list	*temp;
	t_list	*free_temp;
	t_word	*word;
	t_word	*free_word;

	free_word = ((t_list *)lst->content)->content;
	while (lst)
	{
		temp = (t_list *)lst->content;
		while (temp)
		{
			free_temp = temp;
			temp = free_temp->next;
			word = free_temp->content;
			free_split(word->argv);
			free(free_temp);
		}
		temp = lst;
		lst = lst->next;
		free(temp);
	}
	free(free_word);
}
