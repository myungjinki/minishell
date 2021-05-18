/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:30:01 by mki               #+#    #+#             */
/*   Updated: 2021/05/18 18:11:03 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser_dollar_question_mark(t_list *lst_begin, int status)
{
	t_list	*lst_next;
	t_token	*token;

	token = lst_begin->content;
	lst_next = lst_begin->next;
	lst_begin->next = lst_next->next;
	token_free(lst_next);
	token->name = 's';
	token->value = ft_itoa(status);
}

void	parser_env_var(t_list *lst_begin, t_envp_list *lst_envp)
{
	t_list	*lst_tmp;
	t_token	*t;
	char	*join;
	char	*tmp;

	join = (char *)ft_calloc(1, 1);
	t = (lst_begin->next)->content;
	while (t->name == 's' || t->name == '_' || ft_isdigit(t->name))
	{
		tmp = ft_strjoin(join, t->value);
		free(join);
		join = tmp;
		lst_tmp = (lst_begin->next)->next;
		token_free(lst_begin->next);
		lst_begin->next = lst_tmp;
		if (lst_begin->next == NULL)
			return ;
		t = (lst_begin->next)->content;
	}

	t_envp_list	*lst_envp_tmp;

	t = lst_begin->content;
	if ((lst_envp_tmp = ft_find_env(lst_envp, join)))
	{
		t->name = 's';
		t->value = lst_envp_tmp->value;
	}
	else
		t->name = 0;
}

int		parser_env(t_list *lst_begin, t_envp_list *lst_envp, int status)
{
	t_token	*token;

	token = lst_begin->next->content;
	if (token->name == 's' || token->name == '_')
		parser_env_var(lst_begin, lst_envp);
	else if (token->name == '?')
		parser_dollar_question_mark(lst_begin, status);
	else
		return (syntax_error(ERROR_DQUOTES));
	return (0);
}
