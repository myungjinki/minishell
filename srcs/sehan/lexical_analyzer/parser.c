/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:34:33 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:34:35 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

int	syntax_check(t_list *lst_begin)
{
	if (syntax_redirection(lst_begin))
		return (1);
	return (0);
}

int	parser_if(t_list *lst, t_envp_list *lst_envp, char name, int status)
{
	if (name == '\\')
		return (parser_backslash(lst, 0));
	else if (name == '\"')
		return (parser_dquotes(lst, lst_envp, status));
	else if (name == '$')
		return (parser_env(lst, lst_envp, status));
	else if (name == '\'')
		return (parser_quotes(lst));
	return (0);
}

int	string_tokens_join(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;
	t_token	*token_next;
	char	*tmp;

	lst = lst_begin;
	while (lst && lst->next)
	{
		token = lst->content;
		token_next = lst->next->content;
		while (token->name == 's' && token_next->name == 's')
		{
			tmp = ft_strjoin(token->value, token_next->value);
			free(token->value);
			token->value = tmp;
			lst_next_free(lst);
			token = lst->content;
			if (lst->next == NULL)
				break ;
			token_next = lst->next->content;
		}
		lst = lst->next;
	}
	return (0);
}

int	turn_into_string_except_pss(t_list *lst_begin)
{
	t_list	*lst;
	t_token	*token;
	char	c;

	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		c = token->name;
		if (c != ' ' && c != '|' && c != ';' && c != '>' && c != '<')
			token->name = 's';
		lst = lst->next;
	}
	return (0);
}

int	parser(t_list *lst_begin, t_envp_list *lst_envp, int status)
{
	t_list	*lst;
	t_token *token;

	if (syntax_check(lst_begin))
		return (1);
	lst = lst_begin;
	while (lst)
	{
		token = lst->content;
		if (parser_if(lst, lst_envp, token->name, status))
			return (1);
		lst = lst->next;
	}
	turn_into_string_except_pss(lst_begin);
	string_tokens_join(lst_begin);
	return (0);
}
