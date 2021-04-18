/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehan <sehan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:42:57 by sehan             #+#    #+#             */
/*   Updated: 2021/04/18 16:31:08 by sehan            ###   ########.fr       */
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


typedef struct			s_envp_list
{
	struct s_envp_list	*next;
	void				*key;
	void				*value;
}						t_envp_list;

typedef struct			s_d_list
{
	struct s_d_list		*next;
	struct s_d_list		*prev;
	char				*content;
}						t_d_list;

typedef struct			s_mini
{
	t_d_list			*lst_temp;
	t_d_list			*history;
	t_d_list			*head;
	t_envp_list			*env;
	t_envp_list			*env_temp;

	int					c;
	char				*str;
	char				*temp;
	pid_t				pid;
}						t_mini;

extern t_mini g_mini;

int			ft_strcmp(char *s1, char *s2);
void		ft_pwd(t_envp_list *lst);
void		ft_cd(t_envp_list *lst, char *str);
t_envp_list	*ft_find_env(t_envp_list *lst, char *key);
void		ft_envp_lstinit(t_envp_list **lst, char *envp[]);
void		ft_envp_lstadd(t_envp_list **lst, char *str);
void		ft_envp_lstclear(t_envp_list **lst);
void		ft_envp_lstdelone(t_envp_list *lst, char *str);
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
void		ft_add_export(t_mini *mini, char *temp);
void		control_d(t_mini *mini);

void		sig(int signo);

#endif
