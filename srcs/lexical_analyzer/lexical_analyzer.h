/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:31:42 by mki               #+#    #+#             */
/*   Updated: 2021/05/11 13:36:23 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYZER_H
# define LEXICAL_ANALYZER_H
# include "../../libft/libft.h"
# include <stdio.h>

# define	ERROR_QUOTE		1
# define	ERROR_BACKSLASH	2
# define	ERROR_ENV		3

typedef struct			s_word
{
	char				**argv;
	int					*fd_in;
	int					*fd_out;
}						t_word;

typedef struct			s_envp_list
{
	struct s_envp_list	*next;
	void				*key;
	void				*value;
}						t_envp_list;

typedef struct			s_token
{
	int					name;
	char				*value;
}						t_token;

t_list		*lexical_analyzer(char *str, t_envp_list *lst_envp);
t_list		*lexer(char *str);
int			parser(t_list *token, t_envp_list *envp);
int		 	parser_quotes(t_list *lst);
int			parser_backslash_special(t_list *lst_begin);
int			parser_envp(t_list *lst, t_envp_list *envp);
t_list		*executor(char *str);
int			syntax_error(int num);
void		free_token(t_list *lst);

#endif
