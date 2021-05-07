/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:44:16 by mki               #+#    #+#             */
/*   Updated: 2021/05/07 16:30:16 by mki              ###   ########.fr       */
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

t_list	*lexical_analyzer(char *str, char *envp[])
{
	t_list	*ret;

	envp = 0;
	if (!(ret = lexer(str)))
		return (NULL);
	// print_lst_token(ret);
	// ret = NULL;
	// if (!(lst_parser = parser(lst_lexer)))
		// return (NULL);
	// print_lst_token(lst_parser);
	// expander();
	if (!(ret = executor(str)))
		return (NULL);
	return (ret);
}
