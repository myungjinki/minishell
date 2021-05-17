/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:42:57 by sehan             #+#    #+#             */
/*   Updated: 2021/05/17 12:24:47 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ARROW_UP 4283163
# define ARROW_DOWN 4348699
# define DELETE 127
# define ENTER 10
# define CTRL_D 4
# include <stdio.h>
# include <termios.h>
# include <termcap.h>
# include <sys/types.h>
# include "./libft/libft.h"
# include <signal.h>
# include "./srcs/lexical_analyzer/lexical_analyzer.h"

typedef struct			s_d_list
{
	struct s_d_list		*next;
	struct s_d_list		*prev;
	char				*content;
	char				*temp;
}						t_d_list;

typedef struct			s_f_list
{
	int					fd[2];
	struct s_f_list		*next;
}						t_f_list;

typedef struct			s_mini
{
	t_d_list			*history;
	t_d_list			*head;
	t_envp_list			*env;
	t_envp_list			*env_temp;
	t_f_list			*fd_lst;

	int					c;
	char				*str;
	char				*temp;
	pid_t				pid;
	struct termios		term;
	int					status;

	t_list				*lst_parsed;
}						t_mini;

extern t_mini g_mini;

int			ft_strcmp(char *s1, char *s2);
void		ft_pwd(void);
void		ft_cd(t_envp_list *lst, char *str);
t_envp_list	*ft_find_env(t_envp_list *lst, char *key);
void		ft_envp_lstinit(t_envp_list **lst, char *envp[]);
void		ft_envp_lstadd(t_envp_list **lst, char *str);
void		ft_envp_lstclear(t_envp_list **lst);
void		ft_envp_lstdelone(t_envp_list **lst, char *str);
void		term_set(void);
int			ft_stoi(char *str);
void		ft_d_lstadd(t_d_list **lst);
t_d_list	*ft_d_lstnew(void *content);
void		delete_end(int flag);
void		ft_d_lstclear(t_d_list **lst);
void		ft_d_lstadd_back(t_d_list **lst, t_d_list *new);
void		ft_d_lstcopy(t_d_list **src, t_d_list *dst);
void		arrow(t_d_list **lst, int flag);
void		enter(t_mini *mini, char *envp[]);
void		mini_init(t_mini *mini, char *envp[]);
void		free_split(char **str);
void		ft_env(t_mini mini, char *str);
void		ft_exit(t_mini *mini, char *temp);
void		ft_add_export(t_mini *mini, char **temp);
void		control_d(t_mini *mini);
void		backup_term(t_mini *mini);
void		t_f_lstadd_back(t_f_list **lst);
t_f_list	*t_f_lstlast(t_f_list *lst);
void		sig(int signo);
void		t_f_lstclear(t_f_list **lst);
void		is_pipe(t_mini *mini, char *envp[]);
void		not_builtin(t_mini *mini, char *envp[], t_list *lst);
void		is_not_pipe(t_mini *mini, char *envp[]);
void		unset(t_envp_list **lst, char **str);
void		ft_lst_free(t_list *lst);

#endif
