/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 16:31:42 by mki               #+#    #+#             */
/*   Updated: 2021/05/06 17:39:52 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICAL_ANALYZER_H
# define LEXICAL_ANALYZER_H
# include "../../libft/libft.h"
# include <stdio.h>

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
t_list		*parser(t_list *token);
t_list		*executor(char *str);

#endif
