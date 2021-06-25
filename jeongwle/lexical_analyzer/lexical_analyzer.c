/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:44:16 by mki               #+#    #+#             */
/*   Updated: 2021/06/21 17:41:02 by jeongwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/minishell.h"

void	print_lst_token(t_list *lst)
{
	t_token	*token;

	while (lst)
	{
		token = lst->content;
		printf("%c: %s\n", token->name, token->value);
		lst = lst->next;
	}
}

t_list	*lexical_helper(char *str)
{
	char	*trim;
	t_list	*lst;

	trim = ft_strtrim(str, " ");
	if (syntax_multline(trim))
	{
		free(trim);
		return (NULL);
	}
	if (!(lst = lexer(trim)))
	{
		lst_token_free(lst);
		free(trim);
		return (NULL);
	}
	free(trim);
	return (lst);
}

t_list	*lexical_analyzer(char *str, t_mini *mini, int status)
{
	t_list	*lst_word;
	t_list	*lst;
	t_word	*word;

	lst = lexical_helper(str);
	if (lst == NULL)
		return (NULL);
	if (parser(lst, mini, status))
	{
		lst_token_free(lst);
		return (NULL);
	}
	word = make_word(lst);
	lst_word = make_word_list(lst, &word);
	lst_token_free(lst);
	if (!lst_word)
		return (NULL);
	return (lst_word);
}
