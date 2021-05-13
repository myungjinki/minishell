/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:31:42 by mki               #+#    #+#             */
/*   Updated: 2021/05/13 15:38:11 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYZER_H
# define LEXICAL_ANALYZER_H
# include "../../libft/libft.h"
# include <stdio.h>

# define	ERROR_BACKSLASH	0x01
# define	ERROR_DQUOTES	0x02
# define	ERROR_ENV		0x04
# define	ERROR_QUOTES	0x04
# define	ERROR_SEMICOLON	0x08

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
	char				name;
	char				*value;
}						t_token;

t_list		*executor(char *str);
void		free_token(t_list *lst);
t_list		*lexer(char *str);
t_list		*lexical_analyzer(char *str, t_envp_list *lst_envp);
int			parser_backslash(t_list *lst_begin, int flag);
int			parser_dquotes(t_list *lst_begin, t_envp_list *lst_envp);
int			parser_env(t_list *lst_begin, t_envp_list *lst_envp);
int			parser_pipeline(t_list *lst_begin);
int		 	parser_quotes(t_list *lst_begin);
int		 	parser_redirection(t_list *lst_begin);
int			parser_semicolon(t_list *lst_begin);
int			parser(t_list *lst_begin, t_envp_list *lst_envp);
int			syntax_error(int num);

#endif
