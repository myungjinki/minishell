/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 12:30:01 by mki               #+#    #+#             */
/*   Updated: 2021/05/18 11:26:00 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser_dollar_question_mark(t_list *lst_begin)
{
	lst_begin = 0;
}

void	parser_env_var(t_list *lst_begin, t_envp_list *lst_envp)
{
	t_list	*lst_tmp;
	t_token	*t;
	char	*join;
	char	*tmp;

	join = (char *)ft_calloc(1, 1);
	while (lst_begin->next)
	{
		t = lst_begin->next->content;
		if (t->name == 's' || t->name == '_' || ft_isdigit(t->name))
		{
			tmp = ft_strjoin(join, t->value);
			free(join);
			join = tmp;
		}
		lst_tmp = lst_begin->next->next;
		token_free(lst_begin->next);
		lst_begin->next = lst_tmp;
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

int		parser_env(t_list *lst_begin, t_envp_list *lst_envp)
{
	t_token	*token;

	token = lst_begin->next->content;
	if (token->name == 's' || token->name == '_')
		parser_env_var(lst_begin, lst_envp);
	else if (token->name == '?')
		parser_dollar_question_mark(lst_begin);
	else
		return (syntax_error(ERROR_DQUOTES));
	return (0);
}
