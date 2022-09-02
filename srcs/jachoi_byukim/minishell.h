/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byukim <byukim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 22:01:58 by jachoi            #+#    #+#             */
/*   Updated: 2021/01/16 04:52:45 by byukim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define SHELL_NAME "minishell"
# define TOKEN_FILE -1
# define TOKEN_NORMAL 0
# define TOKEN_OUT_REDIR 1
# define TOKEN_APPEND 2
# define TOKEN_IN_REDIR 3
# define TOKEN_PIPE 4
# define TOKEN_SEMICOLON 5
# define MAX_ARGS 512
# define MAX_FILENAME 1024
# include "Libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>

typedef struct	s_token
{
	char			*data;
	int				type;
	struct s_token	*next;
}				t_token;
typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;
typedef struct	s_process
{
	char			argv[MAX_ARGS][MAX_FILENAME];
	char			file_in[MAX_ARGS][MAX_FILENAME];
	char			file_out[MAX_ARGS][MAX_FILENAME];
	bool			is_append[MAX_ARGS];
	int				idx;
	int				in_idx;
	int				out_idx;
	bool			is_pipe;
	bool			prev_pipe;
}				t_process;

t_token			*g_token;
t_env			*g_env;
t_list			*g_path;
t_process		*g_procmgr[MAX_ARGS];
int				g_laststat;
int				g_pipe[MAX_ARGS][2];
pid_t			g_pids[MAX_ARGS];
int				g_fds[MAX_ARGS];
void			free_2d_array(char **arr);
char			*append_char(char *org, char c);
void			prompt(void);
void			cmd(char *command);
int				ft_exit(int exitcode);
int				total_env();
char			**env_to_arr(void);
void			setup_env(char **envp);
void			setup_path(void);
t_env			*get_env(char *key);
char			*tokenizer(char *cmd);
char			*end_tokenizer(void);
void			clear_token(void);
char			*get_env_value(char *key);
void			parse_and_exec(void);
t_process		*process(t_token *tok);
void			assign_type(t_token *iter);
char			*type_definer(t_token *next);
char			*check_parse_error(void);
char			*case_backslash(char *cmd);
int				ft_execvp(char *file, char **argv);
int				escape_count(char *src, int s);
char			**process_argv(t_process *proc);
char			*pre_tokenizer(char *src, int d, int s, char status);
void			wrapper_cd(t_process *proc);
void			wrapper_exit(t_process *proc);
void			wrapper_env(void);
void			exec_normal(t_process *proc);
void			exec_pipe(t_process *proc);
void			exec_pipe_else(t_process *proc);
void			exec_cmdline(void);
pid_t			wrapper_execvp(t_process *proc);
void			wrapper_export(t_process *proc);
void			wrapper_unset(t_process *proc);
void			wrapper_pwd(t_process *proc);
void			wrapper_echo(t_process *proc);
void			wrapper_echo_pipe(t_process *proc);
bool			valid_identifier(char *s);
void			process_redir_in(t_process *proc);
void			process_redir_out(t_process *proc);
#endif
