/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 16:12:02 by mki               #+#    #+#             */
/*   Updated: 2021/04/26 12:59:04 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		lst_print(t_d_list *lst)
{
	t_d_list	*tmp;

	while (lst)
	{
		tmp = lst->content;
		while (tmp)
		{
			printf("%s\n", tmp->content);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

t_d_list	*token_pipe(char *s)
{
	char		**split_pipe;
	t_d_list	*ret;
	int			i;
	
	split_pipe = ft_split(s, '|');
	ret = NULL;
	i = -1;
	while (split_pipe[++i])
	{
		ft_d_lstadd_back(&ret, ft_d_lstnew(split_pipe[i]));
	}
	return (ret);
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
	{
		ft_d_lstadd_back(&ret, ft_d_lstnew(token_pipe(split_semi[i])));
	}
	return (ret);
}

void	token(t_mini *mini, char **envp)
{
	t_d_list	*tmp;

	envp = 0;
	mini->token.lst_semi = token_semi(mini->lst_temp->content);
	tmp = mini->token.lst_semi->content;
	printf("%s\n", tmp->content);
	// lst_print(mini->token.lst_semi);
}
