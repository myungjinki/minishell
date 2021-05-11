/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:31:42 by mki               #+#    #+#             */
/*   Updated: 2021/05/11 12:26:06 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYZER_H
# define LEXICAL_ANALYZER_H
# include "../../libft/libft.h"
# include <stdio.h>

# define	ERROR_QUOTE		1
# define	ERROR_BACKSLASH	2

typedef struct			s_word
{
	char				**argv;
	int					*fd_in;
	int					*fd_out;
}						t_word;

typedef struct			s_token
{
	int					name;
	char				*value;
}						t_token;

t_list		*lexical_analyzer(char *str, char *envp[]);
t_list		*lexer(char *str);
int			parser(t_list *token);
int		 	parser_quotes(t_list *lst);
int			parser_backslash_special(t_list *lst_begin);
t_list		*executor(char *str);
int			syntax_error(int num);
void		free_token(t_list *lst);

#endif
