/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:10:01 by mki               #+#    #+#             */
/*   Updated: 2021/05/03 10:14:53 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		lst_print(t_list *lst)
{
	t_list	*tmp;
	char	**str;
	int		i;

	while (lst)
	{
		tmp = lst->content;
		while (tmp)
		{
			str = (char **)tmp->content;
			i = 0;
			while (str[i])
				printf("%s\n", str[i++]);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

char	**token_string(char *s)
{
	char	**ret;
	
	ret = NULL;
	ret = ft_split(s, ' ');
	return (ret);
}

t_list	*token_pipe(char *s)
{
	char		**split_pipe;
	t_list		*ret;
	int			i;
	
	split_pipe = ft_split(s, '|');
	ret = NULL;
	i = -1;
	while (split_pipe[++i])
	{
		ft_lstadd_back(&ret, ft_lstnew(token_string(split_pipe[i])));
	}
	return (ret);
}

t_list	*token_semi(char *s)
{
	char		**split_semi;
	t_list	*ret;
	int			i;

	split_semi = ft_split(s, ';');
	ret = NULL;
	i = -1;
	while (split_semi[++i])
	{
		ft_lstadd_back(&ret, ft_lstnew(token_pipe(split_semi[i])));
	}
	return (ret);
}

void	token(t_mini *mini, char **envp)
{
	envp = 0;
	mini->lst = token_semi(mini->lst_temp->content);
//	lst_print(mini->token.lst);
}