/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:40:18 by sehan             #+#    #+#             */
/*   Updated: 2021/06/14 20:57:42 by sehan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	pid_fork(t_mini *mini, char *envp[], t_list *lst)
{
	t_word	*word;

	word = lst->content;
	mini->pid[0] = fork();
	if (mini->pid[0] == 0)
	{
		not_builtin(mini, envp, lst);
		exit(0);
	}
	else
		wait(&mini->status);
	free(mini->pid);
	mini->pid = 0;
}

static void	redirection(int *std_fd, t_word *word)
{
	pipe(std_fd);
	dup2(0, std_fd[0]);
	dup2(1, std_fd[1]);
	if (word->fd_in > 0)
		dup2(word->fd_in, 0);
	if (word->fd_out > 0)
		dup2(word->fd_out, 1);
}

static void	redirection_end(int *std_fd)
{
	dup2(std_fd[0], 0);
	dup2(std_fd[1], 1);
}

static void	cd_export_env(t_mini *mini, char **split)
{
	if (!ft_strcmp(split[0], "cd"))
		ft_cd(mini->env, split[1]);
	else if (ft_strcmp(split[0], "export") == 0 && split[1])
		ft_add_export(mini, split);
	else if (!ft_strcmp(split[0], "env") || !ft_strcmp(split[0], "export"))
		ft_env(*mini, split[0]);
}

void		is_not_pipe(t_mini *mini, char *envp[], t_list *lst)
{
	char	**split;
	t_word	*word;
	int		std_fd[2];

	word = lst->content;
	split = word->argv;
	if (split)
	{
		mini->pid = (pid_t *)malloc(sizeof(pid_t));
		redirection(std_fd, word);
		if (ft_strcmp(split[0], "pwd") == 0)
			ft_pwd();
		else if (!ft_strcmp(split[0], "cd") || (!ft_strcmp(split[0], "export")
				&& split[1]) || !ft_strcmp(split[0], "env") ||
				!ft_strcmp(split[0], "export"))
			cd_export_env(mini, split);
		else if (ft_strcmp(split[0], "exit") == 0)
			ft_exit(mini, split[0]);
		else if (ft_strcmp(split[0], "unset") == 0)
			unset(&mini->env, split);
		else
			pid_fork(mini, envp, lst);
		redirection_end(std_fd);
	}
}
