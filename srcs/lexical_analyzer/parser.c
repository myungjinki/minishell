/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/10 20:59:17 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

t_list	*make_string(t_list *start, t_list *end)
{
	t_token *token;
	int		len;

	len = 0;
	start = start->next;
	while (start != end)
	{
		token = start->content;
		len += ft_strlen(token->value);
		start = start->next;
	}
	// printf("len: %d\n", len);
	return (end);
}

t_list	*find_quotes(t_list *lst, char c)
{
	t_token	*token;

	lst = lst->next;
	while (lst)
	{
		token = lst->content;
		// printf("%s\n", token->value);
		if (token->name == c)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

t_list 	*syntax_quotes(t_list *lst)
{
	t_list	*ret;
	t_list	*end;
	t_token *token;

	ret = lst;
	end = NULL;
	while (lst)
	{
		printf("start: %p\n", lst->next);
		token = lst->content;
		if (token->name == '\'')
			end = find_quotes(lst, '\'');
		if (end)
			lst = make_string(lst, end);
		else
		{
			printf("wrong quote syntax");
			return (NULL);
		}
		printf("end: %p\n", lst->next);
		lst = lst->next;
	}
	return (ret);
}

// t_list	*syntax_pipe_semi(t_list *lst, int token_name)
// {
// 	return (lst);
// }

// t_list *syntax_redirection(t_list *lst, int token_name)
// {
// 	return (lst);
// }

// t_list	*syntax(t_list **lst, t_token *token)
// {
// 	if (token->name == '\'')
// 		*lst = syntax_quotes(*lst, token->name);
// 	else if (token->name == '\\')
// 		*lst = syntax_quotes(*lst, token->name);
// 	else if (token->name == ';' || token->name == '|')
// 		*lst = syntax_pipe_semi(*lst, token->name);
// 	else if (token->name == '>' || token->name == '<')
// 		*lst = syntax_redirection(*lst, token->name);
// 	else
// 		*lst = (*lst)->next;
// 	return (*lst);
// }

t_list	*parser(t_list *lst_token)
{
	t_list	*ret;

	ret = lst_token;
	ret = syntax_quotes(lst_token);
	return (ret);
}
