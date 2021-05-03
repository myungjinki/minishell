/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 12:44:16 by mki               #+#    #+#             */
/*   Updated: 2021/05/03 19:32:13 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

int		lexical_analyzer(t_mini *mini, char *envp[])
{
	t_list	*lst_lexer;
	t_list	*lst_parser;

	if (!(lst_lexer = lexer(mini->lst_temp->content)))
		return (1);
	// print_token(lst_lexer);
	if (!(lst_parser = parser(lst_lexer)))
		return (1);
	// expander();
	if (executor(mini, envp))
		return (1);
	return (0);
}
