/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:34:59 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:35:03 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	parser_dollar_question_mark(t_list *lst_begin, int status)
{
	t_list	*lst_next;
	t_token	*token;

	token = lst_begin->content;
	lst_next = lst_begin->next;
	lst_begin->next = lst_next->next;
	token_free(lst_next);
	token->name = 's';
	free(token->value);
	token->value = ft_itoa(status);
}

void	parser_env_trans(t_list *lst_begin, t_envp_list *lst_envp, char *key)
{
	t_envp_list	*lst_envp_tmp;
	t_token		*token;

	token = lst_begin->content;
	if ((lst_envp_tmp = ft_find_env(lst_envp, key)))
	{
		token->name = 's';
		free(token->value);
		token->value = ft_strdup(lst_envp_tmp->value);
	}
	else
	{
		token->name = 0;
		token->value[0] = '\0';
	}
	free(key);
}

void	parser_env_var(t_list *lst_begin, t_envp_list *lst_envp)
{
	t_token	*t;
	char	*key;
	char	*tmp;

	key = (char *)ft_calloc(1, 1);
	t = lst_begin->next->content;
	while (t->name == 's' || t->name == '_' || ft_isdigit(t->name))
	{
		tmp = ft_strjoin(key, t->value);
		free(key);
		key = tmp;
		lst_next_free(lst_begin);
		if (lst_begin->next == NULL)
			break ;
		else
			t = lst_begin->next->content;
	}
	parser_env_trans(lst_begin, lst_envp, key);
}

int		parser_env(t_list *lst_begin, t_envp_list *lst_envp, int status)
{
	t_token	*token;
	char	c;

	if (lst_begin->next)
	{
		token = lst_begin->next->content;
		c = token->name;
		if (token->name == 's' || token->name == '_')
			parser_env_var(lst_begin, lst_envp);
		else if (token->name == '?')
			parser_dollar_question_mark(lst_begin, status);
		else if (ft_isspace(c) || ft_ismeta(c) || ft_isquotes(c))
		{
			token = lst_begin->content;
			token->name = 's';
		}
		else
			return (1);
	}
	return (0);
}
