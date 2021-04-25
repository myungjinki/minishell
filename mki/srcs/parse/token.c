/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:12:02 by mki               #+#    #+#             */
/*   Updated: 2021/04/25 16:47:14 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		lst_print(t_d_list *lst)
{
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}

t_d_list	*token_semi(char *s)
{
	char		**split_semi;
	t_d_list	*ret;
	int			i;

	split_semi = ft_split(s, ';');
	ret = NULL;
	i = -1;
	while (split_semi[++i])
		ft_d_lstadd_back(&ret, ft_d_lstnew(split_semi[i]));
	// free_split(split_semi);
	return (ret);
}

void	token(t_mini *mini)
{
	mini->token.lst_semi = token_semi(mini->lst_temp->content);
	
	lst_print(mini->token.lst_semi);
}
