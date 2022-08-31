/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujeon <yujeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 19:33:25 by yujeon            #+#    #+#             */
/*   Updated: 2021/06/22 19:33:28 by yujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

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

t_list	*lexical_analyzer(char *str, t_envp_list *lst_envp, int status)
{
	t_list	*lst_word;
	t_list	*lst;
	char	*trim;
	t_word	*word;

	trim = ft_strtrim(str, " ");
	if (syntax_multline(trim))
	{
		free(trim);
		return (NULL);
	}
	if (!(lst = lexer(trim)))
		return (NULL);
	free(trim);
	if (parser(lst, lst_envp, status))
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
