/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:12:50 by mki               #+#    #+#             */
/*   Updated: 2021/05/11 13:21:42 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexical_analyzer.h"

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

// t_word	*word_new(char *str)
// {
// 	t_word	*ret;

// 	ret = (t_word *)malloc(sizeof(t_word));
// 	ret->argv[0] = str;
// 	ret->fd_in = NULL;
// 	ret->fd_out = NULL;
// 	return (ret);
// }

int	parser(t_list *lst_begin, char *envp[])
{
	if (parser_quotes(lst_begin))
		return (syntax_error(ERROR_QUOTE));
	if (parser_backslash_special(lst_begin))
		return (syntax_error(ERROR_BACKSLASH));
	if (parser_env(lst_begin, envp))
		return (syntax_error(ERROR_ENV));
	return (0);
}
