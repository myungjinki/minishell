/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:44:16 by mki               #+#    #+#             */
/*   Updated: 2021/05/06 17:33:20 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

void	print_token(t_list *lst)
{
	t_token	*token;

	while (lst)
	{
		token = lst->content;
		printf("%c: %s\n", token->name, token->value);
		lst = lst->next;
	}
}

t_list	*lexical_analyzer(char *str, char *envp[])
{
	t_list	*ret;
	t_list	*lst_lexer;
	t_list	*lst_parser;

	envp = 0;
	if (!(lst_lexer = lexer(str)))
		return (NULL);
	// print_token(lst_lexer);
	if (!(lst_parser = parser(lst_lexer)))
		return (NULL);
	// expander();
	if (!(ret = executor(str)))
		return (NULL);
	return (ret);
}
