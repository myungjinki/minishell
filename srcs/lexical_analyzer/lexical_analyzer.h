;/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:31:42 by mki               #+#    #+#             */
/*   Updated: 2021/06/09 12:17:16 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYZER_H
# define LEXICAL_ANALYZER_H
# include "../../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

# define	BACKSLASH_MULTI			0x0001
# define	DQUOTES_MULTI			0x0002
# define	QUOTES_MULTI			0x0004
# define	SEMICOLON_SYNTAX		0x0008
# define	SEMICOLONS_SYNTAX		0x0010
# define	PIPELINE_SYNTAX			0x0020
# define	PIPELINES_SYNTAX		0x0040
# define	PIPELINE_MULTI			0x0080
# define	R_REDIRECTION_SYNTAX	0x0100
# define	R_REDIRECTIONS_SYNTAX	0x0200
# define	L_REDIRECTION_SYNTAX	0x0400

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

t_list		*executor(char *str, t_list *lst_begin);
int			ft_isall(char c);
int			ft_ismeta(char c);
int			ft_isquotes(char c);
int			ft_isspace(char c);
int			ft_isspecial(char c);
t_list		*lexer(char *str);
t_list		*lexical_analyzer(char *str, t_envp_list *lst_envp, int status);
t_list		*make_string(t_list *start, t_list *end);
int			parser_backslash(t_list *lst_begin, int mode);
int			parser_dquotes(t_list *lst_begin, t_envp_list *lst_envp, int status);
int			parser_env(t_list *lst_begin, t_envp_list *lst_envp, int status);
int			parser_pipeline(t_list *lst_begin);
int		 	parser_quotes(t_list *lst_begin);
int		 	parser_redirection(t_list *lst_begin);
int			parser_semicolon(t_list *lst_begin);
int			parser(t_list *lst_begin, t_envp_list *lst_envp, int status);
int			syntax_backslash(t_list *lst_begin);
int			syntax_dquotes(t_list *lst_begin);
int			syntax_error(int num);
int			syntax_multline(char *str);
int			syntax_pipeline(t_list *lst_begin);
int			syntax_quotes(t_list *lst_begin);
int			syntax_redirection(t_list *lst_begin);
int			syntax_semicolon(t_list *lst_begin);
t_list		*token_find(t_list *lst, char c);
void		token_free(t_list *lst);
void		lst_token_free(t_list *start, t_list *end);
t_list		*lst_next_free(t_list *lst);
t_list		*make_word(t_list *lst);
void		print_lst_token(t_list *lst);

#endif
