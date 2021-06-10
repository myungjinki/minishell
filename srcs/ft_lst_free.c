/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:13:06 by sehan             #+#    #+#             */
/*   Updated: 2021/06/10 21:48:15 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lst_free(t_list *lst)
{
	t_list	*temp;
	t_list	*free_temp;
	t_word	*word;

	while (lst)
	{
		temp = (t_list *)lst->content;
		while (temp)
		{
			free_temp = temp;
			temp = free_temp->next;
			word = free_temp->content;
			printf("%p\n", word->argv[0]);
			free_split(word->argv);
			free(word);
			free(free_temp);
		}
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}
