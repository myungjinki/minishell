/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:28:59 by sehan             #+#    #+#             */
/*   Updated: 2021/04/21 18:19:24 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exe(t_mini *mini, char *envp[], char **split, int i)
{
	if (ft_strcmp(split[i], "pwd") == 0)
		ft_pwd(mini->env);
	else if (ft_strncmp(split[i], "cd ", 3) == 0 ||
			(!ft_strcmp(split[i], "cd") && ft_strlen(split[i]) == 2))
		ft_cd(mini->env, split[i] + 3);
	else if (ft_strcmp(split[i], "env") == 0 ||
			ft_strcmp(split[i], "export") == 0)
		ft_env(*mini, split[i]);
	else if (ft_strncmp(split[i], "export ", 7) == 0)
		ft_add_export(mini, split[i]);
	else if (ft_strcmp(split[i], "exit") == 0)
		ft_exit(mini, split[i]);
	else if (ft_strncmp(split[i], "unset ", 6) == 0)
		ft_envp_lstdelone(mini->env, ft_strtrim(split[i] + 6, " "));
	else
	{
		close(mini->fd_lst->next->fd[0]);
		dup2(mini->fd_lst->fd[0], 0);
		if (split[i + 1])
			dup2(mini->fd_lst->next->fd[1], 1);
		not_builtin(mini, envp, split[i]);
		mini->pid = 0;
	}
	exit(0);
}

void		is_pipe(t_mini *mini, char *envp[], char **split)
{
	int i;

	i = 0;
	while (split[i])
	{
		mini->fd_lst = t_f_lstlast(mini->fd_lst);
		t_f_lstadd_back(&mini->fd_lst);
		pipe(mini->fd_lst->next->fd);
		mini->pid = fork();
		if (mini->pid == 0)
			exe(mini, envp, split, i);
		else
		{
			wait(NULL);
			close(mini->fd_lst->next->fd[1]);
			close(mini->fd_lst->fd[0]);
		}
		i++;
	}
}
