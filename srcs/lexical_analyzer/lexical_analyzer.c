/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:44:16 by mki               #+#    #+#             */
/*   Updated: 2021/05/17 13:34:54 by mki              ###   ########.fr       */
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

t_list	*lexical_analyzer(char *str, t_envp_list *lst_envp)
{
	t_list	*ret;

	if (!(ret = lexer(str)))
		return (NULL);
	if (parser(ret, lst_envp))
		return (NULL);
	print_lst_token(ret);
	lst_envp = 0;
	lst_token_free(ret);
	if (!(ret = executor(str)))
		return (NULL);

	return (ret);
}
